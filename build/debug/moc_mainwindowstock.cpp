/****************************************************************************
** Meta object code from reading C++ file 'mainwindowstock.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindowstock.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowstock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowstockENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowstockENDCLASS = QtMocHelpers::stringData(
    "MainWindowstock",
    "onajouterclicked",
    "",
    "onsupprimerclicked",
    "onmodifierclicked",
    "onvaliderclicked",
    "displayStocks",
    "onTriButtonClicked",
    "onRechercheTextChanged",
    "text",
    "exportToPDF",
    "loadAndDisplayStock",
    "QFrame*",
    "frame",
    "checkStockAlerts",
    "ajouterFourniture",
    "populateFournisseurComboBox",
    "afficherHistoriqueFourniture",
    "exportToTextFile"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowstockENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    1,  104,    2, 0x08,    7 /* Private */,
      10,    0,  107,    2, 0x08,    9 /* Private */,
      11,    1,  108,    2, 0x08,   10 /* Private */,
      14,    0,  111,    2, 0x08,   12 /* Private */,
      15,    0,  112,    2, 0x08,   13 /* Private */,
      16,    0,  113,    2, 0x08,   14 /* Private */,
      17,    0,  114,    2, 0x08,   15 /* Private */,
      18,    0,  115,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindowstock::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowstockENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowstockENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowstockENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindowstock, std::true_type>,
        // method 'onajouterclicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onsupprimerclicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onmodifierclicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onvaliderclicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayStocks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTriButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRechercheTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'exportToPDF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadAndDisplayStock'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFrame *, std::false_type>,
        // method 'checkStockAlerts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ajouterFourniture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'populateFournisseurComboBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherHistoriqueFourniture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportToTextFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindowstock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindowstock *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onajouterclicked(); break;
        case 1: _t->onsupprimerclicked(); break;
        case 2: _t->onmodifierclicked(); break;
        case 3: _t->onvaliderclicked(); break;
        case 4: _t->displayStocks(); break;
        case 5: _t->onTriButtonClicked(); break;
        case 6: _t->onRechercheTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->exportToPDF(); break;
        case 8: _t->loadAndDisplayStock((*reinterpret_cast< std::add_pointer_t<QFrame*>>(_a[1]))); break;
        case 9: _t->checkStockAlerts(); break;
        case 10: _t->ajouterFourniture(); break;
        case 11: _t->populateFournisseurComboBox(); break;
        case 12: _t->afficherHistoriqueFourniture(); break;
        case 13: _t->exportToTextFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QFrame* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindowstock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowstock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowstockENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowstock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
