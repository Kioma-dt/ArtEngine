/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
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
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "SlotSearch"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "SlotFiltr"
QT_MOC_LITERAL(4, 33, 7), // "SlotFix"
QT_MOC_LITERAL(5, 41, 9), // "SlotUnFix"
QT_MOC_LITERAL(6, 51, 10), // "SlotChange"
QT_MOC_LITERAL(7, 62, 19), // "SlotUpdateProcesses"
QT_MOC_LITERAL(8, 82, 16), // "SlotChangeHotKey"
QT_MOC_LITERAL(9, 99, 13), // "SlotFindValue"
QT_MOC_LITERAL(10, 113, 11), // "targetValue"
QT_MOC_LITERAL(11, 125, 9), // "uintptr_t"
QT_MOC_LITERAL(12, 135, 12), // "startAddress"
QT_MOC_LITERAL(13, 148, 10), // "endAddress"
QT_MOC_LITERAL(14, 159, 14), // "SlotFiltrArray"
QT_MOC_LITERAL(15, 174, 9), // "SlotReHot"
QT_MOC_LITERAL(16, 184, 4), // "ctrl"
QT_MOC_LITERAL(17, 189, 3), // "alt"
QT_MOC_LITERAL(18, 193, 5), // "shift"
QT_MOC_LITERAL(19, 199, 7), // "Qt::Key"
QT_MOC_LITERAL(20, 207, 3) // "key"

    },
    "MainWindow\0SlotSearch\0\0SlotFiltr\0"
    "SlotFix\0SlotUnFix\0SlotChange\0"
    "SlotUpdateProcesses\0SlotChangeHotKey\0"
    "SlotFindValue\0targetValue\0uintptr_t\0"
    "startAddress\0endAddress\0SlotFiltrArray\0"
    "SlotReHot\0ctrl\0alt\0shift\0Qt::Key\0key"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    3,   71,    2, 0x08 /* Private */,
      14,    1,   78,    2, 0x08 /* Private */,
      15,    4,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11, 0x80000000 | 11,   10,   12,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 19,   16,   17,   18,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SlotSearch(); break;
        case 1: _t->SlotFiltr(); break;
        case 2: _t->SlotFix(); break;
        case 3: _t->SlotUnFix(); break;
        case 4: _t->SlotChange(); break;
        case 5: _t->SlotUpdateProcesses(); break;
        case 6: _t->SlotChangeHotKey(); break;
        case 7: _t->SlotFindValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< uintptr_t(*)>(_a[2])),(*reinterpret_cast< uintptr_t(*)>(_a[3]))); break;
        case 8: _t->SlotFiltrArray((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->SlotReHot((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< Qt::Key(*)>(_a[4]))); break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
