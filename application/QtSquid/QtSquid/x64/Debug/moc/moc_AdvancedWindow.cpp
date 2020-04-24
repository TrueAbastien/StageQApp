/****************************************************************************
** Meta object code from reading C++ file 'AdvancedWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AdvancedWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdvancedWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdvancedWindow_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdvancedWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdvancedWindow_t qt_meta_stringdata_AdvancedWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AdvancedWindow"
QT_MOC_LITERAL(1, 15, 14), // "setCurrentPage"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6) // "pageID"

    },
    "AdvancedWindow\0setCurrentPage\0\0pageID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdvancedWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void AdvancedWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdvancedWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCurrentPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdvancedWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_AdvancedWindow.data,
    qt_meta_data_AdvancedWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdvancedWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdvancedWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdvancedWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AdvancedWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_CreationWindow_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreationWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreationWindow_t qt_meta_stringdata_CreationWindow = {
    {
QT_MOC_LITERAL(0, 0, 14) // "CreationWindow"

    },
    "CreationWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreationWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CreationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CreationWindow::staticMetaObject = { {
    &AdvancedWindow::staticMetaObject,
    qt_meta_stringdata_CreationWindow.data,
    qt_meta_data_CreationWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CreationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreationWindow.stringdata0))
        return static_cast<void*>(this);
    return AdvancedWindow::qt_metacast(_clname);
}

int CreationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AdvancedWindow::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SettingWindow_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingWindow_t qt_meta_stringdata_SettingWindow = {
    {
QT_MOC_LITERAL(0, 0, 13) // "SettingWindow"

    },
    "SettingWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SettingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SettingWindow::staticMetaObject = { {
    &AdvancedWindow::staticMetaObject,
    qt_meta_stringdata_SettingWindow.data,
    qt_meta_data_SettingWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingWindow.stringdata0))
        return static_cast<void*>(this);
    return AdvancedWindow::qt_metacast(_clname);
}

int SettingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AdvancedWindow::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
