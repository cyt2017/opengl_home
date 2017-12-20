/****************************************************************************
** Meta object code from reading C++ file 'camerabase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../camera/camerabase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camerabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraBase_t {
    QByteArrayData data[13];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraBase_t qt_meta_stringdata_CameraBase = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CameraBase"
QT_MOC_LITERAL(1, 11, 14), // "reciveKeyEvent"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "KEYMODE"
QT_MOC_LITERAL(4, 35, 4), // "type"
QT_MOC_LITERAL(5, 40, 16), // "reciveMouseEvent"
QT_MOC_LITERAL(6, 57, 9), // "MOUSEMODE"
QT_MOC_LITERAL(7, 67, 10), // "CELL::int2"
QT_MOC_LITERAL(8, 78, 2), // "pS"
QT_MOC_LITERAL(9, 81, 2), // "pE"
QT_MOC_LITERAL(10, 84, 16), // "reciveWheelEvent"
QT_MOC_LITERAL(11, 101, 1), // "p"
QT_MOC_LITERAL(12, 103, 5) // "point"

    },
    "CameraBase\0reciveKeyEvent\0\0KEYMODE\0"
    "type\0reciveMouseEvent\0MOUSEMODE\0"
    "CELL::int2\0pS\0pE\0reciveWheelEvent\0p\0"
    "point"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    3,   32,    2, 0x0a /* Public */,
      10,    3,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 7, 0x80000000 | 7,    4,    8,    9,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, 0x80000000 | 7,    4,   11,   12,

       0        // eod
};

void CameraBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraBase *_t = static_cast<CameraBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reciveKeyEvent((*reinterpret_cast< KEYMODE(*)>(_a[1]))); break;
        case 1: _t->reciveMouseEvent((*reinterpret_cast< MOUSEMODE(*)>(_a[1])),(*reinterpret_cast< CELL::int2(*)>(_a[2])),(*reinterpret_cast< CELL::int2(*)>(_a[3]))); break;
        case 2: _t->reciveWheelEvent((*reinterpret_cast< MOUSEMODE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< CELL::int2(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject CameraBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraBase.data,
      qt_meta_data_CameraBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraBase.stringdata0))
        return static_cast<void*>(const_cast< CameraBase*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
