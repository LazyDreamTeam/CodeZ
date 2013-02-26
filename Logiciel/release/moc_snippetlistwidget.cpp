/****************************************************************************
** Meta object code from reading C++ file 'snippetlistwidget.h'
**
** Created: Sun 21. Oct 12:04:42 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../snippetlistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snippetlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SnippetListWidget[] = {

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
      19,   18,   18,   18, 0x05,
      32,   18,   18,   18, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SnippetListWidget[] = {
    "SnippetListWidget\0\0suprPushed()\0"
    "insertPushed()\0"
};

void SnippetListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SnippetListWidget *_t = static_cast<SnippetListWidget *>(_o);
        switch (_id) {
        case 0: _t->suprPushed(); break;
        case 1: _t->insertPushed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SnippetListWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SnippetListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_SnippetListWidget,
      qt_meta_data_SnippetListWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SnippetListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SnippetListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SnippetListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SnippetListWidget))
        return static_cast<void*>(const_cast< SnippetListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int SnippetListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
void SnippetListWidget::suprPushed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SnippetListWidget::insertPushed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
