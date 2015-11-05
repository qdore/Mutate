#-------------------------------------------------
#
# Project created by QtCreator 2014-09-11T14:07:34
#
#-------------------------------------------------

QT       += core gui x11extras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(qxtglobalshortcut/qxtglobalshortcut.pri)
include(qtsinglecoreapplication/qtsinglecoreapplication.pri)

isEmpty(PREFIX) {
 PREFIX = /usr/local/bin
}

TARGET = mutate
TEMPLATE = app
target.path = $$PREFIX/
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
    gpixbuftoqicon.cpp \
    theme.cpp


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
    gpixbuftoqicon.h \
    theme.h


FORMS    += widget.ui \
    setting.ui \
    hotkey.ui \
    listitem.ui \
    doublelistitem.ui

INCLUDEPATH += ../include\

LIBS += -lX11 -L../libs -lboost_regex\

CONFIG += c++11\
          link_pkgconfig

PKGCONFIG += gtk+-2.0\
             gio-2.0

RESOURCES += \
    icons.qrc


