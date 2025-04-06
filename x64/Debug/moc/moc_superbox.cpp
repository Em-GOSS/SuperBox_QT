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
    QByteArrayData data[27];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SuperBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SuperBox_t qt_meta_stringdata_SuperBox = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SuperBox"
QT_MOC_LITERAL(1, 9, 19), // "PlayerTimer_TimeOut"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "EnemyTimer_TimeOut"
QT_MOC_LITERAL(4, 49, 15), // "UITimer_TimeOut"
QT_MOC_LITERAL(5, 65, 19), // "PhysicTimer_TimeOut"
QT_MOC_LITERAL(6, 85, 7), // "CallBag"
QT_MOC_LITERAL(7, 93, 12), // "CallSelectUI"
QT_MOC_LITERAL(8, 106, 10), // "CallSelect"
QT_MOC_LITERAL(9, 117, 10), // "CallBattle"
QT_MOC_LITERAL(10, 128, 9), // "Selecting"
QT_MOC_LITERAL(11, 138, 1), // "i"
QT_MOC_LITERAL(12, 140, 11), // "Selecting_1"
QT_MOC_LITERAL(13, 152, 11), // "Selecting_2"
QT_MOC_LITERAL(14, 164, 11), // "Selecting_3"
QT_MOC_LITERAL(15, 176, 17), // "SwitchBullet_Left"
QT_MOC_LITERAL(16, 194, 18), // "SwitchBullet_Right"
QT_MOC_LITERAL(17, 213, 11), // "UI_TimeTick"
QT_MOC_LITERAL(18, 225, 12), // "PlayerUpdate"
QT_MOC_LITERAL(19, 238, 11), // "EnemyUpdate"
QT_MOC_LITERAL(20, 250, 15), // "Physic_TimeTick"
QT_MOC_LITERAL(21, 266, 18), // "PlayerBulletUpdate"
QT_MOC_LITERAL(22, 285, 17), // "EnemyBulletUpdate"
QT_MOC_LITERAL(23, 303, 12), // "SaveIconSave"
QT_MOC_LITERAL(24, 316, 4), // "Save"
QT_MOC_LITERAL(25, 321, 11), // "saveSlot_ID"
QT_MOC_LITERAL(26, 333, 4) // "Load"

    },
    "SuperBox\0PlayerTimer_TimeOut\0\0"
    "EnemyTimer_TimeOut\0UITimer_TimeOut\0"
    "PhysicTimer_TimeOut\0CallBag\0CallSelectUI\0"
    "CallSelect\0CallBattle\0Selecting\0i\0"
    "Selecting_1\0Selecting_2\0Selecting_3\0"
    "SwitchBullet_Left\0SwitchBullet_Right\0"
    "UI_TimeTick\0PlayerUpdate\0EnemyUpdate\0"
    "Physic_TimeTick\0PlayerBulletUpdate\0"
    "EnemyBulletUpdate\0SaveIconSave\0Save\0"
    "saveSlot_ID\0Load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SuperBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x06 /* Public */,
       3,    0,  130,    2, 0x06 /* Public */,
       4,    0,  131,    2, 0x06 /* Public */,
       5,    0,  132,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  133,    2, 0x0a /* Public */,
       7,    0,  134,    2, 0x0a /* Public */,
       8,    0,  135,    2, 0x0a /* Public */,
       9,    0,  136,    2, 0x0a /* Public */,
      10,    1,  137,    2, 0x0a /* Public */,
      12,    0,  140,    2, 0x0a /* Public */,
      13,    0,  141,    2, 0x0a /* Public */,
      14,    0,  142,    2, 0x0a /* Public */,
      15,    0,  143,    2, 0x0a /* Public */,
      16,    0,  144,    2, 0x0a /* Public */,
      17,    0,  145,    2, 0x0a /* Public */,
      18,    0,  146,    2, 0x0a /* Public */,
      19,    0,  147,    2, 0x0a /* Public */,
      20,    0,  148,    2, 0x0a /* Public */,
      21,    0,  149,    2, 0x0a /* Public */,
      22,    0,  150,    2, 0x0a /* Public */,
      23,    0,  151,    2, 0x0a /* Public */,
      24,    1,  152,    2, 0x0a /* Public */,
      26,    1,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   25,

       0        // eod
};

void SuperBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SuperBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PlayerTimer_TimeOut(); break;
        case 1: _t->EnemyTimer_TimeOut(); break;
        case 2: _t->UITimer_TimeOut(); break;
        case 3: _t->PhysicTimer_TimeOut(); break;
        case 4: _t->CallBag(); break;
        case 5: _t->CallSelectUI(); break;
        case 6: _t->CallSelect(); break;
        case 7: _t->CallBattle(); break;
        case 8: _t->Selecting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->Selecting_1(); break;
        case 10: _t->Selecting_2(); break;
        case 11: _t->Selecting_3(); break;
        case 12: _t->SwitchBullet_Left(); break;
        case 13: _t->SwitchBullet_Right(); break;
        case 14: _t->UI_TimeTick(); break;
        case 15: _t->PlayerUpdate(); break;
        case 16: _t->EnemyUpdate(); break;
        case 17: _t->Physic_TimeTick(); break;
        case 18: _t->PlayerBulletUpdate(); break;
        case 19: _t->EnemyBulletUpdate(); break;
        case 20: _t->SaveIconSave(); break;
        case 21: _t->Save((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->Load((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SuperBox::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SuperBox::PlayerTimer_TimeOut)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SuperBox::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SuperBox::EnemyTimer_TimeOut)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SuperBox::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SuperBox::UITimer_TimeOut)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SuperBox::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SuperBox::PhysicTimer_TimeOut)) {
                *result = 3;
                return;
            }
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void SuperBox::PlayerTimer_TimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SuperBox::EnemyTimer_TimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SuperBox::UITimer_TimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SuperBox::PhysicTimer_TimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
