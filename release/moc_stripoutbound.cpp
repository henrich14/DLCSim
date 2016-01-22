/****************************************************************************
** Meta object code from reading C++ file 'stripoutbound.h'
**
** Created: Mon 1. Jun 17:14:14 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../stripoutbound.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stripoutbound.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StripOutbound[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   15,   14,   14, 0x05,
      71,   62,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   14,   14,   14, 0x08,
     125,  112,   14,   14, 0x08,
     157,  112,   14,   14, 0x08,
     210,  185,   14,   14, 0x08,
     259,  253,   14,   14, 0x08,
     282,   14,   14,   14, 0x08,
     318,  298,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StripOutbound[] = {
    "StripOutbound\0\0callsign,point\0"
    "changeDirectWP(QString,QString)\0"
    "callsign\0STRIP_closed(QString)\0"
    "updateStrip_slot()\0fromcallsign\0"
    "terminate_clicked_slot(QString)\0"
    "logon_clicked_slot(QString)\0"
    "fromCallSign,flightLevel\0"
    "actualflightLevel_changed(QString,QString)\0"
    "point\0point_changed(QString)\0"
    "changeInStrip()\0callsign,flightplan\0"
    "receiveFlightPlan(QString,QString)\0"
};

void StripOutbound::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StripOutbound *_t = static_cast<StripOutbound *>(_o);
        switch (_id) {
        case 0: _t->changeDirectWP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->STRIP_closed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateStrip_slot(); break;
        case 3: _t->terminate_clicked_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->logon_clicked_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->actualflightLevel_changed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->point_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->changeInStrip(); break;
        case 8: _t->receiveFlightPlan((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StripOutbound::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StripOutbound::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StripOutbound,
      qt_meta_data_StripOutbound, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StripOutbound::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StripOutbound::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StripOutbound::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StripOutbound))
        return static_cast<void*>(const_cast< StripOutbound*>(this));
    return QDialog::qt_metacast(_clname);
}

int StripOutbound::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void StripOutbound::changeDirectWP(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StripOutbound::STRIP_closed(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
