/****************************************************************************
** Meta object code from reading C++ file 'radarwindow.h'
**
** Created: Sat 22. Aug 19:47:53 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../radarwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radarwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RadarWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      50,   41,   12,   12, 0x05,
     100,   77,   12,   12, 0x05,
     158,  136,   12,   12, 0x05,
     215,  195,   12,   12, 0x05,
     266,  247,   12,   12, 0x05,
     315,  300,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     345,   12,   12,   12, 0x08,
     379,  362,   12,   12, 0x08,
     421,  414,   12,   12, 0x08,
     450,   12,   12,   12, 0x08,
     473,  468,   12,   12, 0x08,
     498,  468,   12,   12, 0x08,
     538,  529,   12,   12, 0x08,
     564,   12,   12,   12, 0x08,
     611,  581,   12,   12, 0x08,
     652,  247,   12,   12, 0x08,
     721,  689,   12,   12, 0x08,
     764,  300,   12,   12, 0x08,
     801,  300,   12,   12, 0x08,
     839,  830,   12,   12, 0x08,
     873,  860,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RadarWindow[] = {
    "RadarWindow\0\0changeEmergencyStatus(bool)\0"
    "callsign\0closed_connection(QString)\0"
    "callsign,CFL,actual_FL\0"
    "CFLclicked(QString,QString,QString)\0"
    "fileName,callSign,ETE\0"
    "NextPointETE(QString,QString,double)\0"
    "CallSign,flightPlan\0sendFlightPlan(QString,QString)\0"
    "callsign,actual_WP\0directWP_clicked(QString,QString)\0"
    "callsign,point\0sendDirectWP(QString,QString)\0"
    "update_drawing()\0callSign,message\0"
    "dataFromFlightSim(QString,QString)\0"
    "number\0update_flightHistoryNum(int)\0"
    "changeselection()\0text\0aircraftClicked(QString)\0"
    "deselectAircraft_slot(QString)\0dataFrom\0"
    "getSTRIPDataFrom(QString)\0GSclicked_slot()\0"
    "callsign,actual_CFL,actual_FL\0"
    "CFLclicked_slot(QString,QString,QString)\0"
    "DirectWPcliked_slot(QString,QString)\0"
    "callsign,selected_cfl,actual_FL\0"
    "CFLselection_slot(QString,QString,QString)\0"
    "changeDirectWP_slot(QString,QString)\0"
    "getDirectWP(QString,QString)\0mousepos\0"
    "getMousePos(QPointF)\0leftMousePos\0"
    "getLeftMousePos(QPointF)\0"
};

void RadarWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RadarWindow *_t = static_cast<RadarWindow *>(_o);
        switch (_id) {
        case 0: _t->changeEmergencyStatus((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->closed_connection((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->CFLclicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->NextPointETE((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 4: _t->sendFlightPlan((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->directWP_clicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->sendDirectWP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->update_drawing(); break;
        case 8: _t->dataFromFlightSim((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->update_flightHistoryNum((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 10: _t->changeselection(); break;
        case 11: _t->aircraftClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->deselectAircraft_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->getSTRIPDataFrom((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->GSclicked_slot(); break;
        case 15: _t->CFLclicked_slot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 16: _t->DirectWPcliked_slot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 17: _t->CFLselection_slot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 18: _t->changeDirectWP_slot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->getDirectWP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 20: _t->getMousePos((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 21: _t->getLeftMousePos((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RadarWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RadarWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RadarWindow,
      qt_meta_data_RadarWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RadarWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RadarWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RadarWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RadarWindow))
        return static_cast<void*>(const_cast< RadarWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RadarWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void RadarWindow::changeEmergencyStatus(const bool & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RadarWindow::closed_connection(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RadarWindow::CFLclicked(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RadarWindow::NextPointETE(const QString & _t1, const QString & _t2, const double & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RadarWindow::sendFlightPlan(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RadarWindow::directWP_clicked(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RadarWindow::sendDirectWP(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
