/****************************************************************************
** Meta object code from reading C++ file 'rosmanager.h'
**
** Created: Fri Nov 18 12:23:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rosmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rosmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ROSManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   12,   11,   11, 0x05,
      65,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ROSManager[] = {
    "ROSManager\0\0topic_info\0"
    "newTopicAvailable(ros::master::TopicInfo)\0"
    "updateModel()\0refresh()\0"
};

const QMetaObject ROSManager::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ROSManager,
      qt_meta_data_ROSManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ROSManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ROSManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ROSManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ROSManager))
        return static_cast<void*>(const_cast< ROSManager*>(this));
    return QThread::qt_metacast(_clname);
}

int ROSManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newTopicAvailable((*reinterpret_cast< ros::master::TopicInfo(*)>(_a[1]))); break;
        case 1: updateModel(); break;
        case 2: refresh(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ROSManager::newTopicAvailable(ros::master::TopicInfo _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ROSManager::updateModel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
