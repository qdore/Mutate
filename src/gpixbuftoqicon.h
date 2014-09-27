#ifndef GPIXBUFTOQICON_H
#define GPIXBUFTOQICON_H

#include <QIcon>
#undef signals
extern "C" {
#include <gtk/gtk.h>
}

QIcon* giconToQIcon(GdkPixbuf* gicon);

#endif // GPIXBUFTOQICON_H
