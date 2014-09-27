#include "gpixbuftoqicon.h"
#undef signals
#include <QtGui/QImage>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>
#include <QtCore/QtDebug>
#undef signals
extern "C" {
#include <glib.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
}

QImage toQImage(GdkPixbuf *pixbuf) {
    gchar *buffer;
    gsize buffer_size;
    GError *error = 0;
    const gboolean success = gdk_pixbuf_save_to_buffer(
        pixbuf, &buffer, &buffer_size, "png", &error, NULL);
    if (!success) {
        Q_ASSERT(error);
        qWarning() << "conversion failed:" << error->message;
        g_error_free(error);
        return QImage();
    } else {
        // wrap pointers into byte array to avoid sign issues:  The buffer is
        // plain "char", but "QImage::loadFromData()" expects "unsigned char".
        // Thus we wrap the buffer into a QByteArray which uses plain "char",
        // too.  By using "fromRawData()" instead of the constructor we avoid a
        // superfluous copy of image data.
        const QByteArray data = QByteArray::fromRawData(buffer, buffer_size);
        QImage image;
        image.loadFromData(data);
        g_free(buffer);
        return image;
    }
}
QIcon* giconToQIcon(GdkPixbuf* gicon)
{
    QPixmap pixmap = QPixmap::fromImage(toQImage(gicon));
    return new QIcon(pixmap);
}
