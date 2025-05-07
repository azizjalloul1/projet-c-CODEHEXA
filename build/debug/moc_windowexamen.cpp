/****************************************************************************
** Meta object code from reading C++ file 'windowexamen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../windowexamen.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowexamen.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWindowExamenENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWindowExamenENDCLASS = QtMocHelpers::stringData(
    "WindowExamen",
    "retour",
    "",
    "afficherExamens",
    "ajouterExamen",
    "remplirCombo",
    "modif",
    "i",
    "modifierExamen",
    "supprimerExamen",
    "ExporterPDF",
    "TRIC",
    "TRID",
    "TRIDATE",
    "TriCombo",
    "CHERCHER",
    "id",
    "Statistiques",
    "uploadPDF",
    "QRCodeImage",
    "text",
    "QRCode",
    "lireDonneesArduino",
    "ValeurSuperieuregaz",
    "valeurGaz"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWindowExamenENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x08,    1 /* Private */,
       3,    0,  129,    2, 0x08,    2 /* Private */,
       4,    0,  130,    2, 0x08,    3 /* Private */,
       5,    0,  131,    2, 0x08,    4 /* Private */,
       6,    1,  132,    2, 0x08,    5 /* Private */,
       8,    0,  135,    2, 0x08,    7 /* Private */,
       9,    0,  136,    2, 0x08,    8 /* Private */,
      10,    0,  137,    2, 0x08,    9 /* Private */,
      11,    0,  138,    2, 0x08,   10 /* Private */,
      12,    0,  139,    2, 0x08,   11 /* Private */,
      13,    0,  140,    2, 0x08,   12 /* Private */,
      14,    1,  141,    2, 0x08,   13 /* Private */,
      15,    1,  144,    2, 0x08,   15 /* Private */,
      17,    0,  147,    2, 0x08,   17 /* Private */,
      18,    0,  148,    2, 0x08,   18 /* Private */,
      19,    1,  149,    2, 0x08,   19 /* Private */,
      21,    0,  152,    2, 0x08,   21 /* Private */,
      22,    0,  153,    2, 0x08,   22 /* Private */,
      23,    1,  154,    2, 0x08,   23 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QPixmap, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

Q_CONSTINIT const QMetaObject WindowExamen::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSWindowExamenENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWindowExamenENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWindowExamenENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WindowExamen, std::true_type>,
        // method 'retour'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherExamens'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ajouterExamen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'remplirCombo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modif'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'modifierExamen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'supprimerExamen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ExporterPDF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TRIC'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TRID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TRIDATE'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TriCombo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'CHERCHER'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'Statistiques'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'uploadPDF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'QRCodeImage'
        QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'QRCode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lireDonneesArduino'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ValeurSuperieuregaz'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void WindowExamen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowExamen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->retour(); break;
        case 1: _t->afficherExamens(); break;
        case 2: _t->ajouterExamen(); break;
        case 3: _t->remplirCombo(); break;
        case 4: _t->modif((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->modifierExamen(); break;
        case 6: _t->supprimerExamen(); break;
        case 7: _t->ExporterPDF(); break;
        case 8: _t->TRIC(); break;
        case 9: _t->TRID(); break;
        case 10: _t->TRIDATE(); break;
        case 11: _t->TriCombo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->CHERCHER((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->Statistiques(); break;
        case 14: _t->uploadPDF(); break;
        case 15: { QPixmap _r = _t->QRCodeImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->QRCode(); break;
        case 17: _t->lireDonneesArduino(); break;
        case 18: _t->ValeurSuperieuregaz((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *WindowExamen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowExamen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWindowExamenENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WindowExamen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
