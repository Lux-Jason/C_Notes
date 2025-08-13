/****************************************************************************
** Meta object code from reading C++ file 'Client.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Client.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Client.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6ClientE_t {};
} // unnamed namespace

template <> constexpr inline auto Client::qt_create_metaobjectdata<qt_meta_tag_ZN6ClientE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Client",
        "connect_res",
        "",
        "ConnectRes",
        "login_res",
        "LoginRes",
        "recv_sys",
        "std::string",
        "recv_users",
        "recv_private_msg",
        "name",
        "msg",
        "recv_groups",
        "recv_group_msg",
        "group",
        "recv_public_msg",
        "recv_members",
        "recv_muted",
        "deleteUserRes",
        "assignRes",
        "recv_kick_res",
        "recv_kicked",
        "recv_mute_res",
        "recv_unmute_res",
        "recv_new_member",
        "recv_reduce_member",
        "recv_disband_res",
        "recv_join_res",
        "recv_leave_res",
        "recv_create_res",
        "recv_group_disbanded",
        "muted_info"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connect_res'
        QtMocHelpers::SignalData<void(const ConnectRes &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'login_res'
        QtMocHelpers::SignalData<void(const LoginRes &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 2 },
        }}),
        // Signal 'recv_sys'
        QtMocHelpers::SignalData<void(const std::string &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_users'
        QtMocHelpers::SignalData<void(const std::string &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_private_msg'
        QtMocHelpers::SignalData<void(const std::string &, const std::string &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 10 }, { 0x80000000 | 7, 11 },
        }}),
        // Signal 'recv_groups'
        QtMocHelpers::SignalData<void(const std::string &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_group_msg'
        QtMocHelpers::SignalData<void(const std::string &, const std::string &, const std::string &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 14 }, { 0x80000000 | 7, 10 }, { 0x80000000 | 7, 11 },
        }}),
        // Signal 'recv_public_msg'
        QtMocHelpers::SignalData<void(const std::string &, const std::string &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 10 }, { 0x80000000 | 7, 11 },
        }}),
        // Signal 'recv_members'
        QtMocHelpers::SignalData<void(const std::string &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_muted'
        QtMocHelpers::SignalData<void(const std::string &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'deleteUserRes'
        QtMocHelpers::SignalData<void(const std::string &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'assignRes'
        QtMocHelpers::SignalData<void(const std::string &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_kick_res'
        QtMocHelpers::SignalData<void(const std::string &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_kicked'
        QtMocHelpers::SignalData<void(const std::string &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_mute_res'
        QtMocHelpers::SignalData<void(const std::string &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_unmute_res'
        QtMocHelpers::SignalData<void(const std::string &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_new_member'
        QtMocHelpers::SignalData<void(const std::string &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_reduce_member'
        QtMocHelpers::SignalData<void(const std::string &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_disband_res'
        QtMocHelpers::SignalData<void(const std::string &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_join_res'
        QtMocHelpers::SignalData<void(const std::string &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_leave_res'
        QtMocHelpers::SignalData<void(const std::string &)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_create_res'
        QtMocHelpers::SignalData<void(const bool &, const std::string &)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 }, { 0x80000000 | 7, 2 },
        }}),
        // Signal 'recv_group_disbanded'
        QtMocHelpers::SignalData<void(const std::string &)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
        // Signal 'muted_info'
        QtMocHelpers::SignalData<void(const std::string &)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Client, qt_meta_tag_ZN6ClientE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6ClientE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6ClientE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6ClientE_t>.metaTypes,
    nullptr
} };

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Client *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connect_res((*reinterpret_cast< std::add_pointer_t<ConnectRes>>(_a[1]))); break;
        case 1: _t->login_res((*reinterpret_cast< std::add_pointer_t<LoginRes>>(_a[1]))); break;
        case 2: _t->recv_sys((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 3: _t->recv_users((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 4: _t->recv_private_msg((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 5: _t->recv_groups((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 6: _t->recv_group_msg((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3]))); break;
        case 7: _t->recv_public_msg((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 8: _t->recv_members((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 9: _t->recv_muted((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 10: _t->deleteUserRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 11: _t->assignRes((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 12: _t->recv_kick_res((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 13: _t->recv_kicked((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 14: _t->recv_mute_res((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 15: _t->recv_unmute_res((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 16: _t->recv_new_member((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 17: _t->recv_reduce_member((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 18: _t->recv_disband_res((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 19: _t->recv_join_res((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 20: _t->recv_leave_res((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 21: _t->recv_create_res((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 22: _t->recv_group_disbanded((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 23: _t->muted_info((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const ConnectRes & )>(_a, &Client::connect_res, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const LoginRes & )>(_a, &Client::login_res, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_sys, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_users, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & , const std::string & )>(_a, &Client::recv_private_msg, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_groups, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & , const std::string & , const std::string & )>(_a, &Client::recv_group_msg, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & , const std::string & )>(_a, &Client::recv_public_msg, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_members, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_muted, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::deleteUserRes, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::assignRes, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_kick_res, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_kicked, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_mute_res, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_unmute_res, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_new_member, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_reduce_member, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_disband_res, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_join_res, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_leave_res, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const bool & , const std::string & )>(_a, &Client::recv_create_res, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::recv_group_disbanded, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const std::string & )>(_a, &Client::muted_info, 23))
            return;
    }
}

const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6ClientE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void Client::connect_res(const ConnectRes & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void Client::login_res(const LoginRes & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Client::recv_sys(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Client::recv_users(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void Client::recv_private_msg(const std::string & _t1, const std::string & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void Client::recv_groups(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void Client::recv_group_msg(const std::string & _t1, const std::string & _t2, const std::string & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2, _t3);
}

// SIGNAL 7
void Client::recv_public_msg(const std::string & _t1, const std::string & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}

// SIGNAL 8
void Client::recv_members(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void Client::recv_muted(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void Client::deleteUserRes(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void Client::assignRes(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void Client::recv_kick_res(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void Client::recv_kicked(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void Client::recv_mute_res(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void Client::recv_unmute_res(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void Client::recv_new_member(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void Client::recv_reduce_member(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void Client::recv_disband_res(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void Client::recv_join_res(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1);
}

// SIGNAL 20
void Client::recv_leave_res(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1);
}

// SIGNAL 21
void Client::recv_create_res(const bool & _t1, const std::string & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1, _t2);
}

// SIGNAL 22
void Client::recv_group_disbanded(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1);
}

// SIGNAL 23
void Client::muted_info(const std::string & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1);
}
QT_WARNING_POP
