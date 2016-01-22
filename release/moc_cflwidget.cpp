/****************************************************************************
** Meta object code from reading C++ file 'cflwidget.h'
**
** Created: Sun 31. May 17:09:11 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cflwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cflwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CFLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      80,   10,   10,   10, 0x0a,
     100,   10,   10,   10, 0x0a,
     121,   10,   10,   10, 0x0a,
     141,   10,   10,   10, 0x0a,
     160,   10,   10,   10, 0x0a,
     179,   10,   10,   10, 0x0a,
     198,   10,   10,   10, 0x0a,
     217,   10,   10,   10, 0x0a,
     236,   10,   10,   10, 0x0a,
     255,   10,   10,   10, 0x0a,
     274,   10,   10,   10, 0x0a,
     293,   10,   10,   10, 0x0a,
     312,   10,   10,   10, 0x0a,
     332,   10,   10,   10, 0x0a,
     352,   10,   10,   10, 0x0a,
     372,   10,   10,   10, 0x0a,
     392,   10,   10,   10, 0x0a,
     413,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CFLWidget[] = {
    "CFLWidget\0\0callsign,CFL,actual_FL\0"
    "CFLselection_clicked(QString,QString,QString)\0"
    "plus_clicked_slot()\0minus_clicked_slot()\0"
    "five_clicked_slot()\0FL1_clicked_slot()\0"
    "FL2_clicked_slot()\0FL3_clicked_slot()\0"
    "FL4_clicked_slot()\0FL5_clicked_slot()\0"
    "FL6_clicked_slot()\0FL7_clicked_slot()\0"
    "FL8_clicked_slot()\0FL9_clicked_slot()\0"
    "FL10_clicked_slot()\0FL11_clicked_slot()\0"
    "FL12_clicked_slot()\0FL13_clicked_slot()\0"
    "UPLINKclicked_slot()\0CANCELclicked_slot()\0"
};

void CFLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CFLWidget *_t = static_cast<CFLWidget *>(_o);
        switch (_id) {
        case 0: _t->CFLselection_clicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->plus_clicked_slot(); break;
        case 2: _t->minus_clicked_slot(); break;
        case 3: _t->five_clicked_slot(); break;
        case 4: _t->FL1_clicked_slot(); break;
        case 5: _t->FL2_clicked_slot(); break;
        case 6: _t->FL3_clicked_slot(); break;
        case 7: _t->FL4_clicked_slot(); break;
        case 8: _t->FL5_clicked_slot(); break;
        case 9: _t->FL6_clicked_slot(); break;
        case 10: _t->FL7_clicked_slot(); break;
        case 11: _t->FL8_clicked_slot(); break;
        case 12: _t->FL9_clicked_slot(); break;
        case 13: _t->FL10_clicked_slot(); break;
        case 14: _t->FL11_clicked_slot(); break;
        case 15: _t->FL12_clicked_slot(); break;
        case 16: _t->FL13_clicked_slot(); break;
        case 17: _t->UPLINKclicked_slot(); break;
        case 18: _t->CANCELclicked_slot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CFLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CFLWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CFLWidget,
      qt_meta_data_CFLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CFLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CFLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CFLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CFLWidget))
        return static_cast<void*>(const_cast< CFLWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CFLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void CFLWidget::CFLselection_clicked(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
