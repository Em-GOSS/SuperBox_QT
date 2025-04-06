/****************************************************************************
** Meta object code from reading C++ file 'AnimatedGraphicsView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AnimatedGraphicsView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimatedGraphicsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnimatedGraphicsView_t {
    QByteArrayData data[7];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimatedGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimatedGraphicsView_t qt_meta_stringdata_AnimatedGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AnimatedGraphicsView"
QT_MOC_LITERAL(1, 21, 17), // "parameter_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 9), // "parameter"
QT_MOC_LITERAL(4, 50, 7), // "clicked"
QT_MOC_LITERAL(5, 58, 9), // "clickOver"
QT_MOC_LITERAL(6, 68, 8) // "TimeTick"

    },
    "AnimatedGraphicsView\0parameter_clicked\0"
    "\0parameter\0clicked\0clickOver\0TimeTick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimatedGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,
       5,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void AnimatedGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnimatedGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parameter_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->clicked(); break;
        case 2: _t->clickOver(); break;
        case 3: _t->TimeTick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AnimatedGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnimatedGraphicsView::parameter_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AnimatedGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnimatedGraphicsView::clicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AnimatedGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnimatedGraphicsView::clickOver)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AnimatedGraphicsView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_AnimatedGraphicsView.data,
    qt_meta_data_AnimatedGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AnimatedGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimatedGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnimatedGraphicsView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "TimeUpdater"))
        return static_cast< TimeUpdater*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int AnimatedGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AnimatedGraphicsView::parameter_clicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AnimatedGraphicsView::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AnimatedGraphicsView::clickOver()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
