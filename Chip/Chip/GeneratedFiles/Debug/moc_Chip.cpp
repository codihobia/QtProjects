/****************************************************************************
** Meta object code from reading C++ file 'Chip.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Chip.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chip_t {
    QByteArrayData data[11];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chip_t qt_meta_stringdata_Chip = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Chip"
QT_MOC_LITERAL(1, 5, 6), // "OnRead"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 6), // "OnInit"
QT_MOC_LITERAL(4, 20, 10), // "OnNextStep"
QT_MOC_LITERAL(5, 31, 10), // "OnLastStep"
QT_MOC_LITERAL(6, 42, 7), // "OnStart"
QT_MOC_LITERAL(7, 50, 6), // "OnHalt"
QT_MOC_LITERAL(8, 57, 7), // "OnReset"
QT_MOC_LITERAL(9, 65, 6), // "OnWash"
QT_MOC_LITERAL(10, 72, 1) // "a"

    },
    "Chip\0OnRead\0\0OnInit\0OnNextStep\0"
    "OnLastStep\0OnStart\0OnHalt\0OnReset\0"
    "OnWash\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chip[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void Chip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chip *_t = static_cast<Chip *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnRead(); break;
        case 1: _t->OnInit(); break;
        case 2: _t->OnNextStep(); break;
        case 3: _t->OnLastStep(); break;
        case 4: _t->OnStart(); break;
        case 5: _t->OnHalt(); break;
        case 6: _t->OnReset(); break;
        case 7: _t->OnWash((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Chip::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Chip.data,
    qt_meta_data_Chip,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Chip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chip::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chip.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Chip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
