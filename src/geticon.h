#ifndef GETICON_H
#define GETICON_H

#include <QtGui/QImage>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>
#include <QtCore/QtDebug>
#include <QIcon>
#include <QPixmap>
#undef signals

extern "C" {
#include <gdk/gdk.h>
}

QImage toQImage(GdkPixbuf *pixbuf);
QIcon toQIcon(std::string icon);
QIcon toQIcon(GdkPixbuf *pixbuf);

#endif // GETICON_H
