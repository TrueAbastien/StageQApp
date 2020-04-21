/****************************************************************************
** Meta object code from reading C++ file 'ConnectionPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../include/QtSquid/core/page/main/ConnectionPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConnectionPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnectionPage_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectionPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectionPage_t qt_meta_stringdata_ConnectionPage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ConnectionPage"
QT_MOC_LITERAL(1, 15, 15), // "connectDatabase"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "saveDatabaseData"
QT_MOC_LITERAL(4, 49, 12), // "saveUserData"
QT_MOC_LITERAL(5, 62, 13), // "writeEditData"
QT_MOC_LITERAL(6, 76, 3), // "key"
QT_MOC_LITERAL(7, 80, 16) // "setSilentConnect"

    },
    "ConnectionPage\0connectDatabase\0\0"
    "saveDatabaseData\0saveUserData\0"
    "writeEditData\0key\0setSilentConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void ConnectionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectionPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectDatabase(); break;
        case 1: _t->saveDatabaseData(); break;
        case 2: _t->saveUserData(); break;
        case 3: _t->writeEditData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setSilentConnect(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConnectionPage::staticMetaObject = { {
    &Page::staticMetaObject,
    qt_meta_stringdata_ConnectionPage.data,
    qt_meta_data_ConnectionPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConnectionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionPage.stringdata0))
        return static_cast<void*>(this);
    return Page::qt_metacast(_clname);
}

int ConnectionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Page::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
