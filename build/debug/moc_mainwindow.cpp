/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_btnRetourAccueil_clicked",
    "",
    "executePythonScript",
    "promptType",
    "std::function<void()>",
    "callback",
    "startDataCollection",
    "resetInputs",
    "validerMotDePasse",
    "validerEmail",
    "QString&",
    "email",
    "verifierIdExistant",
    "ajouterEmploye",
    "afficherEmployes",
    "supprimerEmploye",
    "modifierEmploye",
    "afficherStatistiques",
    "rechercherEmploye",
    "exportPdf",
    "trierParSalaire"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    2,  105,    2, 0x08,    2 /* Private */,
       7,    0,  110,    2, 0x08,    5 /* Private */,
       8,    0,  111,    2, 0x08,    6 /* Private */,
       9,    0,  112,    2, 0x08,    7 /* Private */,
      10,    1,  113,    2, 0x08,    8 /* Private */,
      13,    0,  116,    2, 0x08,   10 /* Private */,
      14,    0,  117,    2, 0x08,   11 /* Private */,
      15,    0,  118,    2, 0x08,   12 /* Private */,
      16,    0,  119,    2, 0x08,   13 /* Private */,
      17,    0,  120,    2, 0x08,   14 /* Private */,
      18,    0,  121,    2, 0x08,   15 /* Private */,
      19,    0,  122,    2, 0x08,   16 /* Private */,
      20,    0,  123,    2, 0x08,   17 /* Private */,
      21,    0,  124,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 11,   12,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_btnRetourAccueil_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'executePythonScript'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::function<void()>, std::false_type>,
        // method 'startDataCollection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetInputs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'validerMotDePasse'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'validerEmail'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'verifierIdExistant'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ajouterEmploye'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherEmployes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'supprimerEmploye'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modifierEmploye'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherStatistiques'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rechercherEmploye'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportPdf'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'trierParSalaire'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnRetourAccueil_clicked(); break;
        case 1: _t->executePythonScript((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::function<void()>>>(_a[2]))); break;
        case 2: _t->startDataCollection(); break;
        case 3: _t->resetInputs(); break;
        case 4: { bool _r = _t->validerMotDePasse();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->validerEmail((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->verifierIdExistant();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->ajouterEmploye(); break;
        case 8: _t->afficherEmployes(); break;
        case 9: _t->supprimerEmploye(); break;
        case 10: _t->modifierEmploye(); break;
        case 11: _t->afficherStatistiques(); break;
        case 12: _t->rechercherEmploye(); break;
        case 13: _t->exportPdf(); break;
        case 14: _t->trierParSalaire(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
