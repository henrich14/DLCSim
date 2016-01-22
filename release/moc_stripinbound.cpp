/****************************************************************************
** Meta object code from reading C++ file 'stripinbound.h'
**
** Created: Mon 1. Jun 17:14:12 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../stripinbound.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stripinbound.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StripInbound[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   14,   13,   13, 0x05,
      88,   73,   13,   13, 0x05,
     129,  120,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     151,   13,   13,   13, 0x08,
     183,  170,   13,   13, 0x08,
     215,  170,   13,   13, 0x08,
     249,  243,   13,   13, 0x08,
     291,  284,   13,   13, 0x08,
     323,  316,   13,   13, 0x08,
     361,  348,   13,   13, 0x08,
     418,  393,   13,   13, 0x08,
     461,   13,   13,   13, 0x08,
     497,  477,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StripInbound[] = {
    "StripInbound\0\0route,CallSign\0"
    "arrivalRoute_change_signal(QString,QString)\0"
    "callsign,point\0changeDirectWP(QString,QString)\0"
    "callsign\0STRIP_closed(QString)\0"
    "updateStrip_slot()\0fromcallsign\0"
    "terminate_clicked_slot(QString)\0"
    "logon_clicked_slot(QString)\0route\0"
    "arrivalRoute_changed_slot(QString)\0"
    "point1\0point_1_changed(QString)\0point2\0"
    "point_2_changed(QString)\0fromCallSign\0"
    "arrivalRoute_confirmed(QString)\0"
    "fromCallSign,flightLevel\0"
    "actualflightLevel_changed(QString,QString)\0"
    "changeInStrip()\0callsign,flightplan\0"
    "receiveFlightPlan(QString,QString)\0"
};

void StripInbound::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StripInbound *_t = static_cast<StripInbound *>(_o);
        switch (_id) {
        case 0: _t->arrivalRoute_change_signal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->changeDirectWP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->STRIP_closed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->updateStrip_slot(); break;
        case 4: _t->terminate_clicked_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->logon_clicked_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->arrivalRoute_changed_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->point_1_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->point_2_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->arrivalRoute_confirmed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->actualflightLevel_changed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->changeInStrip(); break;
        case 12: _t->receiveFlightPlan((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StripInbound::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StripInbound::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StripInbound,
      qt_meta_data_StripInbound, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StripInbound::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StripInbound::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StripInbound::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StripInbound))
        return static_cast<void*>(const_cast< StripInbound*>(this));
    return QDialog::qt_metacast(_clname);
}

int StripInbound::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void StripInbound::arrivalRoute_change_signal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StripInbound::changeDirectWP(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StripInbound::STRIP_closed(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
