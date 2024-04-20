/****************************************************************************
** Meta object code from reading C++ file 'plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot_t {
    QByteArrayData data[16];
    char stringdata0[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_t qt_meta_stringdata_Plot = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Plot"
QT_MOC_LITERAL(1, 5, 29), // "on_chkShowLegend_stateChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "arg1"
QT_MOC_LITERAL(4, 41, 31), // "on_txtPointCountX_returnPressed"
QT_MOC_LITERAL(5, 73, 31), // "on_txtPointCountY_returnPressed"
QT_MOC_LITERAL(6, 105, 24), // "on_btnColourBack_clicked"
QT_MOC_LITERAL(7, 130, 32), // "on_txtPointOriginX_returnPressed"
QT_MOC_LITERAL(8, 163, 25), // "on_chkTrackX_stateChanged"
QT_MOC_LITERAL(9, 189, 26), // "on_chkAdjustY_stateChanged"
QT_MOC_LITERAL(10, 216, 32), // "on_txtPointOriginY_returnPressed"
QT_MOC_LITERAL(11, 249, 17), // "repPlotCoordinate"
QT_MOC_LITERAL(12, 267, 25), // "on_btnClearGraphs_clicked"
QT_MOC_LITERAL(13, 293, 33), // "on_txtMainScaleNumX_returnPre..."
QT_MOC_LITERAL(14, 327, 33), // "on_txtMainScaleNumY_returnPre..."
QT_MOC_LITERAL(15, 361, 22) // "on_btnSaveData_clicked"

    },
    "Plot\0on_chkShowLegend_stateChanged\0\0"
    "arg1\0on_txtPointCountX_returnPressed\0"
    "on_txtPointCountY_returnPressed\0"
    "on_btnColourBack_clicked\0"
    "on_txtPointOriginX_returnPressed\0"
    "on_chkTrackX_stateChanged\0"
    "on_chkAdjustY_stateChanged\0"
    "on_txtPointOriginY_returnPressed\0"
    "repPlotCoordinate\0on_btnClearGraphs_clicked\0"
    "on_txtMainScaleNumX_returnPressed\0"
    "on_txtMainScaleNumY_returnPressed\0"
    "on_btnSaveData_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
       9,    1,   89,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_chkShowLegend_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_txtPointCountX_returnPressed(); break;
        case 2: _t->on_txtPointCountY_returnPressed(); break;
        case 3: _t->on_btnColourBack_clicked(); break;
        case 4: _t->on_txtPointOriginX_returnPressed(); break;
        case 5: _t->on_chkTrackX_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_chkAdjustY_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_txtPointOriginY_returnPressed(); break;
        case 8: _t->repPlotCoordinate(); break;
        case 9: _t->on_btnClearGraphs_clicked(); break;
        case 10: _t->on_txtMainScaleNumX_returnPressed(); break;
        case 11: _t->on_txtMainScaleNumY_returnPressed(); break;
        case 12: _t->on_btnSaveData_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plot::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Plot.data,
    qt_meta_data_Plot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
