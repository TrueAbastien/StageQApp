/****************************************************************************
** Meta object code from reading C++ file 'EditPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../include/QtSquid/core/page/main/EditPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditPage_t {
    QByteArrayData data[8];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditPage_t qt_meta_stringdata_EditPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EditPage"
QT_MOC_LITERAL(1, 9, 16), // "OpenCreationMenu"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "AddElement"
QT_MOC_LITERAL(4, 38, 13), // "RemoveElement"
QT_MOC_LITERAL(5, 52, 11), // "TakeElement"
QT_MOC_LITERAL(6, 64, 12), // "StoreElement"
QT_MOC_LITERAL(7, 77, 17) // "onDatabaseConnect"

    },
    "EditPage\0OpenCreationMenu\0\0AddElement\0"
    "RemoveElement\0TakeElement\0StoreElement\0"
    "onDatabaseConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenCreationMenu(); break;
        case 1: _t->AddElement(); break;
        case 2: _t->RemoveElement(); break;
        case 3: _t->TakeElement(); break;
        case 4: _t->StoreElement(); break;
        case 5: _t->onDatabaseConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EditPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditPage::OpenCreationMenu)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject EditPage::staticMetaObject = { {
    &Page::staticMetaObject,
    qt_meta_stringdata_EditPage.data,
    qt_meta_data_EditPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditPage.stringdata0))
        return static_cast<void*>(this);
    return Page::qt_metacast(_clname);
}

int EditPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Page::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EditPage::OpenCreationMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
