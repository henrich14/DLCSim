/****************************************************************************
** Meta object code from reading C++ file 'stripoverflight.h'
**
** Created: Mon 1. Jun 17:14:16 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../stripoverflight.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stripoverflight.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StripOverflight[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   17,   16,   16, 0x05,
      73,   64,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   16,   16,   16, 0x08,
     127,  114,   16,   16, 0x08,
     159,  114,   16,   16, 0x08,
     212,  187,   16,   16, 0x08,
     262,  255,   16,   16, 0x08,
     294,  287,   16,   16, 0x08,
     326,  319,   16,   16, 0x08,
     351,   16,   16,   16, 0x08,
     387,  367,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StripOverflight[] = {
    "StripOverflight\0\0callsign,point\0"
    "changeDirectWP(QString,QString)\0"
    "callsign\0STRIP_closed(QString)\0"
    "updateStrip_slot()\0fromcallsign\0"
    "terminate_clicked_slot(QString)\0"
    "logon_clicked_slot(QString)\0"
    "fromCallSign,flightLevel\0"
    "actualflightLevel_changed(QString,QString)\0"
    "point1\0point_1_changed(QString)\0point2\0"
    "point_2_changed(QString)\0point3\0"
    "point_3_changed(QString)\0changeInStrip()\0"
    "callsign,flightplan\0"
    "receiveFlightPlan(QString,QString)\0"
};

void StripOverflight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StripOverflight *_t = static_cast<StripOverflight *>(_o);
        switch (_id) {
        case 0: _t->changeDirectWP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->STRIP_closed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateStrip_slot(); break;
        case 3: _t->terminate_clicked_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->logon_clicked_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->actualflightLevel_changed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->point_1_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->point_2_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->point_3_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->changeInStrip(); break;
        case 10: _t->receiveFlightPlan((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StripOverflight::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StripOverflight::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StripOverflight,
      qt_meta_data_StripOverflight, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StripOverflight::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StripOverflight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StripOverflight::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StripOverflight))
        return static_cast<void*>(const_cast< StripOverflight*>(this));
    return QDialog::qt_metacast(_clname);
}

int StripOverflight::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void StripOverflight::changeDirectWP(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StripOverflight::STRIP_closed(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
