/****************************************************************************
** Meta object code from reading C++ file 'mytextitem.h'
**
** Created: Sun 31. May 10:53:56 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mytextitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytextitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyTextItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      38,   12,   11,   11, 0x05,
      64,   11,   11,   11, 0x05,
     106,   76,   11,   11, 0x05,
     161,  142,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MyTextItem[] = {
    "MyTextItem\0\0text\0textclicked(QString)\0"
    "deselectaircraft(QString)\0GSclicked()\0"
    "callsign,actual_CFL,actual_FL\0"
    "CFLclicked(QString,QString,QString)\0"
    "callsign,actual_wp\0DirectWPclicked(QString,QString)\0"
};

void MyTextItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTextItem *_t = static_cast<MyTextItem *>(_o);
        switch (_id) {
        case 0: _t->textclicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->deselectaircraft((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->GSclicked(); break;
        case 3: _t->CFLclicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->DirectWPclicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyTextItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyTextItem::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_MyTextItem,
      qt_meta_data_MyTextItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyTextItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyTextItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyTextItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTextItem))
        return static_cast<void*>(const_cast< MyTextItem*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int MyTextItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyTextItem::textclicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTextItem::deselectaircraft(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTextItem::GSclicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MyTextItem::CFLclicked(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTextItem::DirectWPclicked(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
