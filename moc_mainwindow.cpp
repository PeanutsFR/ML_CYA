/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata[480];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 24),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 22),
QT_MOC_LITERAL(4, 60, 22),
QT_MOC_LITERAL(5, 83, 19),
QT_MOC_LITERAL(6, 103, 19),
QT_MOC_LITERAL(7, 123, 20),
QT_MOC_LITERAL(8, 144, 21),
QT_MOC_LITERAL(9, 166, 22),
QT_MOC_LITERAL(10, 189, 22),
QT_MOC_LITERAL(11, 212, 23),
QT_MOC_LITERAL(12, 236, 23),
QT_MOC_LITERAL(13, 260, 24),
QT_MOC_LITERAL(14, 285, 22),
QT_MOC_LITERAL(15, 308, 21),
QT_MOC_LITERAL(16, 330, 19),
QT_MOC_LITERAL(17, 350, 24),
QT_MOC_LITERAL(18, 375, 28),
QT_MOC_LITERAL(19, 404, 31),
QT_MOC_LITERAL(20, 436, 19),
QT_MOC_LITERAL(21, 456, 4),
QT_MOC_LITERAL(22, 461, 7),
QT_MOC_LITERAL(23, 469, 9)
    },
    "MainWindow\0on_actionTest4_triggered\0"
    "\0on_actionTest4_hovered\0on_btn_takeoff_clicked\0"
    "on_btn_land_clicked\0on_btn_goup_pressed\0"
    "on_btn_goup_released\0on_btn_godown_pressed\0"
    "on_btn_godown_released\0on_btn_rotleft_pressed\0"
    "on_btn_rotleft_released\0on_btn_rotright_pressed\0"
    "on_btn_rotright_released\0"
    "on_btn_keyctrl_clicked\0on_btn_chgCam_clicked\0"
    "on_btn_anim_clicked\0on_btn_parcourir_clicked\0"
    "on_btn_drone_connect_clicked\0"
    "on_btn_drone_disconnect_clicked\0"
    "on_btn_load_clicked\0test\0fichier\0"
    "updateGUI\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x0a,
       3,    0,  120,    2, 0x0a,
       4,    0,  121,    2, 0x0a,
       5,    0,  122,    2, 0x0a,
       6,    0,  123,    2, 0x0a,
       7,    0,  124,    2, 0x0a,
       8,    0,  125,    2, 0x0a,
       9,    0,  126,    2, 0x0a,
      10,    0,  127,    2, 0x0a,
      11,    0,  128,    2, 0x0a,
      12,    0,  129,    2, 0x0a,
      13,    0,  130,    2, 0x0a,
      14,    0,  131,    2, 0x0a,
      15,    0,  132,    2, 0x0a,
      16,    0,  133,    2, 0x0a,
      17,    0,  134,    2, 0x0a,
      18,    0,  135,    2, 0x0a,
      19,    0,  136,    2, 0x0a,
      20,    0,  137,    2, 0x0a,
      21,    1,  138,    2, 0x0a,
      23,    0,  141,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionTest4_triggered(); break;
        case 1: _t->on_actionTest4_hovered(); break;
        case 2: _t->on_btn_takeoff_clicked(); break;
        case 3: _t->on_btn_land_clicked(); break;
        case 4: _t->on_btn_goup_pressed(); break;
        case 5: _t->on_btn_goup_released(); break;
        case 6: _t->on_btn_godown_pressed(); break;
        case 7: _t->on_btn_godown_released(); break;
        case 8: _t->on_btn_rotleft_pressed(); break;
        case 9: _t->on_btn_rotleft_released(); break;
        case 10: _t->on_btn_rotright_pressed(); break;
        case 11: _t->on_btn_rotright_released(); break;
        case 12: _t->on_btn_keyctrl_clicked(); break;
        case 13: _t->on_btn_chgCam_clicked(); break;
        case 14: _t->on_btn_anim_clicked(); break;
        case 15: _t->on_btn_parcourir_clicked(); break;
        case 16: _t->on_btn_drone_connect_clicked(); break;
        case 17: _t->on_btn_drone_disconnect_clicked(); break;
        case 18: _t->on_btn_load_clicked(); break;
        case 19: _t->test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->updateGUI(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
