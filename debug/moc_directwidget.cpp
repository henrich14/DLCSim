/****************************************************************************
** Meta object code from reading C++ file 'directwidget.h'
**
** Created: Sat 22. Aug 19:48:04 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../directwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'directwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DirectWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   62,   13,   13, 0x0a,
     119,   13,   13,   13, 0x0a,
     140,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DirectWidget[] = {
    "DirectWidget\0\0callsign,directWP\0"
    "sendDirectWP(QString,QString)\0"
    "callsign,actual_WP\0"
    "directWPclicked_slot(QString,QString)\0"
    "UPLINKclicked_slot()\0CANCELclicked_slot()\0"
};

void DirectWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DirectWidget *_t = static_cast<DirectWidget *>(_o);
        switch (_id) {
        case 0: _t->sendDirectWP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->directWPclicked_slot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->UPLINKclicked_slot(); break;
        case 3: _t->CANCELclicked_slot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DirectWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DirectWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DirectWidget,
      qt_meta_data_DirectWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DirectWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DirectWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DirectWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DirectWidget))
        return static_cast<void*>(const_cast< DirectWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DirectWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DirectWidget::sendDirectWP(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
