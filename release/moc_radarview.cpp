/****************************************************************************
** Meta object code from reading C++ file 'radarview.h'
**
** Created: Sun 31. May 18:37:19 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../radarview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radarview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RadarView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      35,   11,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_RadarView[] = {
    "RadarView\0\0point\0mousePos(QPointF)\0"
    "LeftMousePos(QPointF)\0"
};

void RadarView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RadarView *_t = static_cast<RadarView *>(_o);
        switch (_id) {
        case 0: _t->mousePos((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: _t->LeftMousePos((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RadarView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RadarView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_RadarView,
      qt_meta_data_RadarView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RadarView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RadarView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RadarView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RadarView))
        return static_cast<void*>(const_cast< RadarView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int RadarView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RadarView::mousePos(const QPointF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RadarView::LeftMousePos(const QPointF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
