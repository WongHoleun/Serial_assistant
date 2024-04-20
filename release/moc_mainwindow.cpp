/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "on_btnSwitch_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "serialPortRead_Slot"
QT_MOC_LITERAL(4, 53, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(5, 72, 22), // "on_btnClearRec_clicked"
QT_MOC_LITERAL(6, 95, 23), // "on_btnClearSend_clicked"
QT_MOC_LITERAL(7, 119, 22), // "on_chkRec_stateChanged"
QT_MOC_LITERAL(8, 142, 4), // "arg1"
QT_MOC_LITERAL(9, 147, 21), // "on_btnSaveEig_clicked"
QT_MOC_LITERAL(10, 169, 23), // "on_chkSend_stateChanged"
QT_MOC_LITERAL(11, 193, 26), // "on_chkTimSend_stateChanged"
QT_MOC_LITERAL(12, 220, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 242, 17) // "dataRateCalculate"

    },
    "MainWindow\0on_btnSwitch_clicked\0\0"
    "serialPortRead_Slot\0on_btnSend_clicked\0"
    "on_btnClearRec_clicked\0on_btnClearSend_clicked\0"
    "on_chkRec_stateChanged\0arg1\0"
    "on_btnSaveEig_clicked\0on_chkSend_stateChanged\0"
    "on_chkTimSend_stateChanged\0"
    "on_pushButton_clicked\0dataRateCalculate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      11,    1,   81,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnSwitch_clicked(); break;
        case 1: _t->serialPortRead_Slot(); break;
        case 2: _t->on_btnSend_clicked(); break;
        case 3: _t->on_btnClearRec_clicked(); break;
        case 4: _t->on_btnClearSend_clicked(); break;
        case 5: _t->on_chkRec_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btnSaveEig_clicked(); break;
        case 7: _t->on_chkSend_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_chkTimSend_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->dataRateCalculate(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
