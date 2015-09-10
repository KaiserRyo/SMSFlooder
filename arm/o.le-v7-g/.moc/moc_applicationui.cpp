/****************************************************************************
** Meta object code from reading C++ file 'applicationui.hpp'
**
** Created: Mon Nov 18 16:56:44 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/applicationui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   15,   14,   14, 0x05,
      39,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   14,   14,   14, 0x08,
      92,   57,   14,   14, 0x08,
     240,  200,   14,   14, 0x08,

 // methods: signature, parameters, type, tag, flags
     397,  382,   14,   14, 0x02,
     420,   14,   14,   14, 0x02,
     450,  435,   14,   14, 0x02,
     490,  480,  475,   14, 0x02,
     535,  516,   14,   14, 0x02,
     579,  572,   14,   14, 0x02,
     606,  602,   14,   14, 0x02,
     640,  637,  629,   14, 0x02,
     667,  637,  629,   14, 0x02,
     693,  688,   14,   14, 0x02,
     723,  712,   14,   14, 0x02,
     775,  751,  629,   14, 0x02,
     825,  803,   14,   14, 0x02,
     877,  853,   14,   14, 0x02,
    1007,  902,   14,   14, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationUI[] = {
    "ApplicationUI\0\0repeatedTimes\0sent(int)\0"
    "done()\0timedout()\0accountId,conversationId,messageId\0"
    "onMessageAdded(bb::pim::account::AccountKey,bb::pim::message::Conversa"
    "tionKey,bb::pim::message::MessageKey)\0"
    "accountId,conversationId,messageId,data\0"
    "onMessageUpdated(bb::pim::account::AccountKey,bb::pim::message::Conver"
    "sationKey,bb::pim::message::MessageKey,bb::pim::message::MessageUpdate"
    ")\0"
    "interval,times\0startFlooding(int,int)\0"
    "stopFlooding()\0dropDownObject\0"
    "populateEmails(QObject*)\0bool\0text,find\0"
    "contains(QString,QString)\0email,subject,body\0"
    "invokeEmail(QString,QString,QString)\0"
    "appurl\0invokeBBWorld(QString)\0url\0"
    "invokeBrowser(QString)\0QString\0id\0"
    "getContactPhoneNumber(int)\0"
    "getContactEmail(int)\0text\0showToast(QString)\0"
    "title,text\0showDialog(QString,QString)\0"
    "objectName,defaultValue\0"
    "getSetting(QString,QString)\0"
    "objectName,inputValue\0setSetting(QString,QString)\0"
    "recipientNumber,message\0"
    "sendSMS(QString,QString)\0"
    "recipientEmailID,recipientEmailAddress,recipientEmailSubject,messageTe"
    "xt,lastRecordedAudioPath,autoReply\0"
    "sendEmail(int,QString,QString,QString,QString,bool)\0"
};

void ApplicationUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationUI *_t = static_cast<ApplicationUI *>(_o);
        switch (_id) {
        case 0: _t->sent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->done(); break;
        case 2: _t->timedout(); break;
        case 3: _t->onMessageAdded((*reinterpret_cast< bb::pim::account::AccountKey(*)>(_a[1])),(*reinterpret_cast< bb::pim::message::ConversationKey(*)>(_a[2])),(*reinterpret_cast< bb::pim::message::MessageKey(*)>(_a[3]))); break;
        case 4: _t->onMessageUpdated((*reinterpret_cast< bb::pim::account::AccountKey(*)>(_a[1])),(*reinterpret_cast< bb::pim::message::ConversationKey(*)>(_a[2])),(*reinterpret_cast< bb::pim::message::MessageKey(*)>(_a[3])),(*reinterpret_cast< bb::pim::message::MessageUpdate(*)>(_a[4]))); break;
        case 5: _t->startFlooding((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->stopFlooding(); break;
        case 7: _t->populateEmails((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 8: { bool _r = _t->contains((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->invokeEmail((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->invokeBBWorld((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->invokeBrowser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: { QString _r = _t->getContactPhoneNumber((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->getContactEmail((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: _t->showToast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->showDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 16: { QString _r = _t->getSetting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 17: _t->setSetting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 18: _t->sendSMS((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 19: _t->sendEmail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ApplicationUI,
      qt_meta_data_ApplicationUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationUI))
        return static_cast<void*>(const_cast< ApplicationUI*>(this));
    return QObject::qt_metacast(_clname);
}

int ApplicationUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void ApplicationUI::sent(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ApplicationUI::done()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
