#-------------------------------------------------
#
# Project created by QtCreator 2014-09-11T14:07:34
#
#-------------------------------------------------

QT       += core gui xml x11extras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(qxtglobalshortcut/qxtglobalshortcut.pri)
include(qtsinglecoreapplication/qtsinglecoreapplication.pri)

TARGET = mutate
TEMPLATE = app
target.path = /usr/local/bin
INSTALLS = target


SOURCES += main.cpp\
        widget.cpp \
    returnbyscript.cpp \
    defaulsearch.cpp \
    config_parse.cpp \
    setting.cpp \
    plaintext.cpp \
    listwidget.cpp \
    singleapplication.cpp \
    frequenceparse.cpp \
    hotkey.cpp \
    widgetthread.cpp \
    listitem.cpp \
    config.cpp \
    doublelistitem.cpp \
    gpixbuftoqicon.cpp


HEADERS  += widget.h \
    returnbyscript.h \
    defaulsearch.h \
    config_parse.h \
    setting.h \
    hotkey.h \
    plaintext.h \
    listwidget.h \
    singleapplication.h \
    frequenceparse.h \
    widgetthread.h \
    listitem.h \
    config.h \
    doublelistitem.h \
    gpixbuftoqicon.h


FORMS    += widget.ui \
    setting.ui \
    hotkey.ui \
    listitem.ui \
    doublelistitem.ui

INCLUDEPATH += ../include /usr/include/python2.7\
-pthread /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include\
/usr/include/gtk-2.0 /usr/lib/x86_64-linux-gnu/gtk-2.0/include /usr/include/atk-1.0 /usr/include/cairo /usr/include/gdk-pixbuf-2.0 /usr/include/pango-1.0 /usr/include/gio-unix-2.0/ /usr/include/freetype2 /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include /usr/include/pixman-1 /usr/include/libpng12 /usr/include/harfbuzz

LIBS += -lX11 -L../libs -lboost_regex -lboost_python -lpython2.7\
-lgio-2.0 -lgobject-2.0 -lglib-2.0\
-lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo -lpango-1.0 -lfontconfig -lgobject-2.0 -lglib-2.0 -lfreetype

CONFIG += c++11

RESOURCES += \
    icons.qrc


