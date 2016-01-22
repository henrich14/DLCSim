/****************************************************************************
** Meta object code from reading C++ file 'label.h'
**
** Created: Sat 22. Aug 19:47:40 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../label.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Label[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,    7,    6,    6, 0x05,
      43,   35,    6,    6, 0x05,
      69,   35,    6,    6, 0x05,
      95,    6,    6,    6, 0x05,
     116,  111,    6,    6, 0x05,
     149,  144,    6,    6, 0x05,
     186,  177,    6,    6, 0x05,
     225,  218,    6,    6, 0x05,
     264,  255,    6,    6, 0x05,
     301,  296,    6,    6, 0x05,
     340,  334,    6,    6, 0x05,
     375,  369,    6,    6, 0x05,
     404,   35,    6,    6, 0x05,
     428,   35,    6,    6, 0x05,
     450,   35,    6,    6, 0x05,
     476,   35,    6,    6, 0x05,
     499,   35,    6,    6, 0x05,
     524,   35,    6,    6, 0x05,
     555,   35,    6,    6, 0x05,
     591,   35,    6,    6, 0x05,
     613,   35,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     649,    6,    6,    6, 0x08,
     665,    6,    6,    6, 0x08,
     681,    6,    6,    6, 0x08,
     695,    6,    6,    6, 0x08,
     731,  722,    6,    6, 0x08,
     781,  771,  763,    6, 0x08,
     807,  771,  763,    6, 0x08,
     837,    6,    6,    6, 0x08,
     853,  845,    6,    6, 0x08,
     869,    6,    6,    6, 0x08,
     885,    6,    6,    6, 0x08,
     905,    6,    6,    6, 0x08,
     922,    6,    6,    6, 0x08,
     941,    6,    6,    6, 0x08,
     966,    6,    6,    6, 0x08,
     996,    6,    6,    6, 0x08,
    1019,    6,    6,    6, 0x08,
    1049,    6,    6,    6, 0x08,
    1068,   35,    6,    6, 0x08,
    1112, 1101,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Label[] = {
    "Label\0\0qnhClicked\0QNHChecked(bool)\0"
    "message\0FLchange_pending(QString)\0"
    "change_cancelled(QString)\0change_uplink()\0"
    "time\0TIMEchange_pending(QString)\0rate\0"
    "RATEchange_pending(QString)\0altitude\0"
    "ALTITUDEchange_pending(QString)\0radial\0"
    "RADIALchange_pending(QString)\0distance\0"
    "DISTANCEchange_pending(QString)\0freq\0"
    "frequencyChange_pending(QString)\0point\0"
    "pointChange_pending(QString)\0track\0"
    "trackChange_pending(QString)\0"
    "messageChanged(QString)\0roger_signal(QString)\0"
    "disregard_signal(QString)\0"
    "affirm_signal(QString)\0negative_signal(QString)\0"
    "contactRequest_signal(QString)\0"
    "contactRequestVoice_signal(QString)\0"
    "logOn_signal(QString)\0"
    "resumeOwnNavigation_signal(QString)\0"
    "FLchange_slot()\0canceled_slot()\0"
    "uplink_slot()\0radialButtonClicked_slot()\0"
    "PostFreq\0freqChangeClicked_slot(QString)\0"
    "QString\0StripList\0getCurrentFL(QStringList)\0"
    "getCurrentRADIAL(QStringList)\0setFL()\0"
    "QNHdata\0getQNH(QString)\0ROGER_clicked()\0"
    "DISREGARD_clicked()\0AFFIRM_clicked()\0"
    "NEGATIVE_clicked()\0CONTACTrequest_clicked()\0"
    "CONTACTrequestVoice_clicked()\0"
    "logOnclicked_clicked()\0"
    "RESUMEownNavigation_clicked()\0"
    "messageREAD_slot()\0currentMessageREAD_slot(QString)\0"
    "METAR_DATA\0getMetarData(QString)\0"
};

void Label::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Label *_t = static_cast<Label *>(_o);
        switch (_id) {
        case 0: _t->QNHChecked((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->FLchange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->change_cancelled((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->change_uplink(); break;
        case 4: _t->TIMEchange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->RATEchange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->ALTITUDEchange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->RADIALchange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->DISTANCEchange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->frequencyChange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->pointChange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->trackChange_pending((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->messageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->roger_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->disregard_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->affirm_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->negative_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->contactRequest_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->contactRequestVoice_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->logOn_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->resumeOwnNavigation_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->FLchange_slot(); break;
        case 22: _t->canceled_slot(); break;
        case 23: _t->uplink_slot(); break;
        case 24: _t->radialButtonClicked_slot(); break;
        case 25: _t->freqChangeClicked_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: { QString _r = _t->getCurrentFL((*reinterpret_cast< const QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 27: { QString _r = _t->getCurrentRADIAL((*reinterpret_cast< const QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 28: _t->setFL(); break;
        case 29: _t->getQNH((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->ROGER_clicked(); break;
        case 31: _t->DISREGARD_clicked(); break;
        case 32: _t->AFFIRM_clicked(); break;
        case 33: _t->NEGATIVE_clicked(); break;
        case 34: _t->CONTACTrequest_clicked(); break;
        case 35: _t->CONTACTrequestVoice_clicked(); break;
        case 36: _t->logOnclicked_clicked(); break;
        case 37: _t->RESUMEownNavigation_clicked(); break;
        case 38: _t->messageREAD_slot(); break;
        case 39: _t->currentMessageREAD_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->getMetarData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Label::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Label::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Label,
      qt_meta_data_Label, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Label::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Label::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Label))
        return static_cast<void*>(const_cast< Label*>(this));
    return QWidget::qt_metacast(_clname);
}

int Label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}

// SIGNAL 0
void Label::QNHChecked(const bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Label::FLchange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Label::change_cancelled(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Label::change_uplink()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Label::TIMEchange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Label::RATEchange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Label::ALTITUDEchange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Label::RADIALchange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Label::DISTANCEchange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Label::frequencyChange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Label::pointChange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Label::trackChange_pending(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Label::messageChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Label::roger_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Label::disregard_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Label::affirm_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Label::negative_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Label::contactRequest_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Label::contactRequestVoice_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Label::logOn_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Label::resumeOwnNavigation_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}
QT_END_MOC_NAMESPACE
