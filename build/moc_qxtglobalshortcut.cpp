/****************************************************************************
** Meta object code from reading C++ file 'qxtglobalshortcut.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Mutate/qxtglobalshortcut/qxtglobalshortcut.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtglobalshortcut.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QxtGlobalShortcut_t {
    QByteArrayData data[9];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QxtGlobalShortcut_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QxtGlobalShortcut_t qt_meta_stringdata_QxtGlobalShortcut = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 9),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 11),
QT_MOC_LITERAL(4, 41, 10),
QT_MOC_LITERAL(5, 52, 7),
QT_MOC_LITERAL(6, 60, 11),
QT_MOC_LITERAL(7, 72, 8),
QT_MOC_LITERAL(8, 81, 8)
    },
    "QxtGlobalShortcut\0activated\0\0std::string\0"
    "setEnabled\0enabled\0setDisabled\0disabled\0"
    "shortcut\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QxtGlobalShortcut[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   44,    2, 0x0a,
       4,    0,   47,    2, 0x2a,
       6,    1,   48,    2, 0x0a,
       6,    0,   51,    2, 0x2a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::Bool, 0x00095103,
       8, QMetaType::QKeySequence, 0x00095103,

       0        // eod
};

void QxtGlobalShortcut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QxtGlobalShortcut *_t = static_cast<QxtGlobalShortcut *>(_o);
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setEnabled(); break;
        case 3: _t->setDisabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setDisabled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QxtGlobalShortcut::*_t)(std::string , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QxtGlobalShortcut::activated)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QxtGlobalShortcut::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtGlobalShortcut.data,
      qt_meta_data_QxtGlobalShortcut,  qt_static_metacall, 0, 0}
};


const QMetaObject *QxtGlobalShortcut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtGlobalShortcut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtGlobalShortcut.stringdata))
        return static_cast<void*>(const_cast< QxtGlobalShortcut*>(this));
    return QObject::qt_metacast(_clname);
}

int QxtGlobalShortcut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isEnabled(); break;
        case 1: *reinterpret_cast< QKeySequence*>(_v) = shortcut(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 1: setShortcut(*reinterpret_cast< QKeySequence*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QxtGlobalShortcut::activated(std::string _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
