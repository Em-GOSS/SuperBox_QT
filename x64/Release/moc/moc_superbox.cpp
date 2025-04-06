/****************************************************************************
** Meta object code from reading C++ file 'superbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../superbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'superbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SuperBox_t {
    QByteArrayData data[12];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SuperBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SuperBox_t qt_meta_stringdata_SuperBox = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SuperBox"
QT_MOC_LITERAL(1, 9, 7), // "CallBag"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "CallSelectUI"
QT_MOC_LITERAL(4, 31, 10), // "CallSelect"
QT_MOC_LITERAL(5, 42, 10), // "CallBattle"
QT_MOC_LITERAL(6, 53, 9), // "Selecting"
QT_MOC_LITERAL(7, 63, 1), // "i"
QT_MOC_LITERAL(8, 65, 11), // "Selecting_1"
QT_MOC_LITERAL(9, 77, 11), // "Selecting_2"
QT_MOC_LITERAL(10, 89, 11), // "Selecting_3"
QT_MOC_LITERAL(11, 101, 8) // "TimeTick"

    },
    "SuperBox\0CallBag\0\0CallSelectUI\0"
    "CallSelect\0CallBattle\0Selecting\0i\0"
    "Selecting_1\0Selecting_2\0Selecting_3\0"
    "TimeTick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SuperBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    1,   63,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SuperBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SuperBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CallBag(); break;
        case 1: _t->CallSelectUI(); break;
        case 2: _t->CallSelect(); break;
        case 3: _t->CallBattle(); break;
        case 4: _t->Selecting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->Selecting_1(); break;
        case 6: _t->Selecting_2(); break;
        case 7: _t->Selecting_3(); break;
        case 8: _t->TimeTick(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SuperBox::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_SuperBox.data,
    qt_meta_data_SuperBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SuperBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SuperBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SuperBox.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SuperBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
