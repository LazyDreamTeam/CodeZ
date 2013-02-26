/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun 21. Oct 12:04:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x0a,
      48,   11,   11,   11, 0x0a,
      74,   69,   11,   11, 0x0a,
     107,   11,   11,   11, 0x0a,
     121,   69,   11,   11, 0x0a,
     154,   11,   11,   11, 0x0a,
     169,   11,   11,   11, 0x0a,
     186,   11,   11,   11, 0x0a,
     200,   12,   11,   11, 0x0a,
     231,   11,   11,   11, 0x0a,
     251,   69,   11,   11, 0x0a,
     283,   11,   11,   11, 0x0a,
     296,   69,   11,   11, 0x0a,
     328,   11,   11,   11, 0x0a,
     342,   11,   11,   11, 0x0a,
     358,   11,   11,   11, 0x0a,
     373,   11,   11,   11, 0x0a,
     399,  395,   11,   11, 0x0a,
     427,   11,   11,   11, 0x0a,
     435,   11,   11,   11, 0x0a,
     458,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0pos\0showContextMenuCategory(QPoint)\0"
    "setContextCategory()\0item\0"
    "selectCategory(QListWidgetItem*)\0"
    "addCategory()\0renameCategory(QListWidgetItem*)\0"
    "editCategory()\0deleteCategory()\0"
    "showLangage()\0showContextMenuSnippet(QPoint)\0"
    "setContextSnippet()\0selectSnippet(QListWidgetItem*)\0"
    "addSnippet()\0renameSnippet(QListWidgetItem*)\0"
    "editSnippet()\0deleteSnippet()\0"
    "shareSnippet()\0refreshCategoryList()\0"
    "cat\0refreshSnippetList(QString)\0about()\0"
    "updateSnippetContent()\0supressionPushed()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->showContextMenuCategory((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->setContextCategory(); break;
        case 2: _t->selectCategory((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->addCategory(); break;
        case 4: _t->renameCategory((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->editCategory(); break;
        case 6: _t->deleteCategory(); break;
        case 7: _t->showLangage(); break;
        case 8: _t->showContextMenuSnippet((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->setContextSnippet(); break;
        case 10: _t->selectSnippet((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->addSnippet(); break;
        case 12: _t->renameSnippet((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: _t->editSnippet(); break;
        case 14: _t->deleteSnippet(); break;
        case 15: _t->shareSnippet(); break;
        case 16: _t->refreshCategoryList(); break;
        case 17: _t->refreshSnippetList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->about(); break;
        case 19: _t->updateSnippetContent(); break;
        case 20: _t->supressionPushed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
