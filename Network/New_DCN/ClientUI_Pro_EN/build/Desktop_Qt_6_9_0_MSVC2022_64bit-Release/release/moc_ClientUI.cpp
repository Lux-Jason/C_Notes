/****************************************************************************
** Meta object code from reading C++ file 'ClientUI.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ClientUI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
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
struct qt_meta_tag_ZN8ClientUIE_t {};
} // unnamed namespace

template <> constexpr inline auto ClientUI::qt_create_metaobjectdata<qt_meta_tag_ZN8ClientUIE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClientUI",
        "onCustomContextMenuRequested_group",
        "",
        "pos",
        "onCustomContextMenuRequested_member",
        "onCustomContextMenuRequested_muted",
        "onDisbandAct",
        "onJoinAct",
        "onLeaveAct",
        "onKickAct",
        "onMuteAct",
        "onUnmuteAct",
        "onLoginSuccess",
        "onRecvSys",
        "std::string",
        "onRecvUsers",
        "onRecvPrivateMsg",
        "name",
        "msg",
        "onRecvGroups",
        "onRecvGroupMsg",
        "group",
        "onRecvPublicMsg",
        "onRecvDisbandRes",
        "onRecvJoinRes",
        "onRecvLeaveRes",
        "onRecvCreateRes",
        "onRecvMembers",
        "onRecvMuted",
        "onRecvKickRes",
        "onRecvKicked",
        "onRecvMuteRes",
        "onRecvUnmuteRes",
        "onRecvNewMember",
        "onRecvReduceMember",
        "onRecvGroupDisbanded",
        "onMutedInfo",
        "onRecvDeleteUserRes",
        "onRecvAssignRes",
        "on_userBtn_clicked",
        "on_allGroupBtn_clicked",
        "on_createGroupBtn_clicked",
        "on_refreshBtn_clicked",
        "getNewGroupName",
        "on_sendBtn_clicked",
        "on_publicSendBtn_clicked",
        "changeChatWidget",
        "QListWidgetItem*",
        "item",
        "on_memberBtn_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onCustomContextMenuRequested_group'
        QtMocHelpers::SlotData<void(const QPoint &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPoint, 3 },
        }}),
        // Slot 'onCustomContextMenuRequested_member'
        QtMocHelpers::SlotData<void(const QPoint &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPoint, 3 },
        }}),
        // Slot 'onCustomContextMenuRequested_muted'
        QtMocHelpers::SlotData<void(const QPoint &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPoint, 3 },
        }}),
        // Slot 'onDisbandAct'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onJoinAct'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onLeaveAct'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onKickAct'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onMuteAct'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onUnmuteAct'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onLoginSuccess'
        QtMocHelpers::SlotData<void(const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'onRecvSys'
        QtMocHelpers::SlotData<void(const std::string &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvUsers'
        QtMocHelpers::SlotData<void(const std::string &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvPrivateMsg'
        QtMocHelpers::SlotData<void(const std::string &, const std::string &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 17 }, { 0x80000000 | 14, 18 },
        }}),
        // Slot 'onRecvGroups'
        QtMocHelpers::SlotData<void(const std::string &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvGroupMsg'
        QtMocHelpers::SlotData<void(const std::string &, const std::string &, const std::string &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 21 }, { 0x80000000 | 14, 17 }, { 0x80000000 | 14, 18 },
        }}),
        // Slot 'onRecvPublicMsg'
        QtMocHelpers::SlotData<void(const std::string &, const std::string &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 17 }, { 0x80000000 | 14, 18 },
        }}),
        // Slot 'onRecvDisbandRes'
        QtMocHelpers::SlotData<void(const std::string &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvJoinRes'
        QtMocHelpers::SlotData<void(const std::string &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvLeaveRes'
        QtMocHelpers::SlotData<void(const std::string &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvCreateRes'
        QtMocHelpers::SlotData<void(const bool &, const std::string &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 }, { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvMembers'
        QtMocHelpers::SlotData<void(const std::string &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvMuted'
        QtMocHelpers::SlotData<void(const std::string &)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvKickRes'
        QtMocHelpers::SlotData<void(const std::string &)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvKicked'
        QtMocHelpers::SlotData<void(const std::string &)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvMuteRes'
        QtMocHelpers::SlotData<void(const std::string &)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvUnmuteRes'
        QtMocHelpers::SlotData<void(const std::string &)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvNewMember'
        QtMocHelpers::SlotData<void(const std::string &)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvReduceMember'
        QtMocHelpers::SlotData<void(const std::string &)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvGroupDisbanded'
        QtMocHelpers::SlotData<void(const std::string &)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onMutedInfo'
        QtMocHelpers::SlotData<void(const std::string &)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvDeleteUserRes'
        QtMocHelpers::SlotData<void(const std::string &)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'onRecvAssignRes'
        QtMocHelpers::SlotData<void(const std::string &)>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot 'on_userBtn_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_allGroupBtn_clicked'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_createGroupBtn_clicked'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_refreshBtn_clicked'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'getNewGroupName'
        QtMocHelpers::SlotData<void(const QString &)>(43, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'on_sendBtn_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_publicSendBtn_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'changeChatWidget'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 47, 48 },
        }}),
        // Slot 'on_memberBtn_clicked'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClientUI, qt_meta_tag_ZN8ClientUIE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClientUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ClientUIE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ClientUIE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8ClientUIE_t>.metaTypes,
    nullptr
} };

void ClientUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClientUI *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onCustomContextMenuRequested_group((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->onCustomContextMenuRequested_member((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 2: _t->onCustomContextMenuRequested_muted((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->onDisbandAct(); break;
        case 4: _t->onJoinAct(); break;
        case 5: _t->onLeaveAct(); break;
        case 6: _t->onKickAct(); break;
        case 7: _t->onMuteAct(); break;
        case 8: _t->onUnmuteAct(); break;
        case 9: _t->onLoginSuccess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->onRecvSys((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 11: _t->onRecvUsers((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 12: _t->onRecvPrivateMsg((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 13: _t->onRecvGroups((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 14: _t->onRecvGroupMsg((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3]))); break;
        case 15: _t->onRecvPublicMsg((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 16: _t->onRecvDisbandRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 17: _t->onRecvJoinRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 18: _t->onRecvLeaveRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 19: _t->onRecvCreateRes((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 20: _t->onRecvMembers((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 21: _t->onRecvMuted((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 22: _t->onRecvKickRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 23: _t->onRecvKicked((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 24: _t->onRecvMuteRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 25: _t->onRecvUnmuteRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 26: _t->onRecvNewMember((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 27: _t->onRecvReduceMember((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 28: _t->onRecvGroupDisbanded((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 29: _t->onMutedInfo((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 30: _t->onRecvDeleteUserRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 31: _t->onRecvAssignRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 32: _t->on_userBtn_clicked(); break;
        case 33: _t->on_allGroupBtn_clicked(); break;
        case 34: _t->on_createGroupBtn_clicked(); break;
        case 35: _t->on_refreshBtn_clicked(); break;
        case 36: _t->getNewGroupName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->on_sendBtn_clicked(); break;
        case 38: _t->on_publicSendBtn_clicked(); break;
        case 39: _t->changeChatWidget((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 40: _t->on_memberBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *ClientUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ClientUIE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClientUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
