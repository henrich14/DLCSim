/****************************************************************************
** Meta object code from reading C++ file 'timesyncdialog.h'
**
** Created: Fri 29. May 17:58:24 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timesyncdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timesyncdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TimeSyncDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TimeSyncDialog[] = {
    "TimeSyncDialog\0\0timeValue\0"
    "setTime_signal(QString)\0setTime_slot()\0"
};

void TimeSyncDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimeSyncDialog *_t = static_cast<TimeSyncDialog *>(_o);
        switch (_id) {
        case 0: _t->setTime_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setTime_slot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TimeSyncDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TimeSyncDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TimeSyncDialog,
      qt_meta_data_TimeSyncDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimeSyncDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimeSyncDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimeSyncDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimeSyncDialog))
        return static_cast<void*>(const_cast< TimeSyncDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TimeSyncDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void TimeSyncDialog::setTime_signal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE