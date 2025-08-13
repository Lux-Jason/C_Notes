#ifndef CLIENT_H
#define CLIENT_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "DES_c.h" 
#pragma comment(lib, "ws2_32.lib")

#include <QObject>

constexpr int DEFAULT_PORT = 5000;
constexpr int BUFFER_SIZE = 1024;

enum LoginRes
{
	LOGIN_SUCCESS,
	NAME_UESED
};

enum ConnectRes
{
	CONNECT_SUCCESS,
	CONNECT_FALSE
};

// 客户端状态信息
struct ClientState {
	std::string username;
	std::vector<std::string> joinedGroups;
	std::vector<std::string> ownedGroups; // 添加用户创建的组列表
};

class Client : public QObject
{
	Q_OBJECT

public:
	Client();
	~Client();

	static Client* getInstance();

	int start(const std::string &addr, const int &port);
	void stop();

	void HandleInput();
	void PrintHelp();

	// -------- 登录 --------
	void login(const std::string& usrName);

	void listUser();
	void listGroup();
	void sendChat(const std::string &to, const std::string &msg);
	void sendGroupChat(const std::string& to, const std::string& msg);
	void sendPublicChat(const std::string& msg);
	void listMembers(const std::string &group);
	void listMuted(const std::string& group);
	void kick(const std::string& group, const std::string& name);
	void mute(const std::string& group, const std::string& name);
	void unmute(const std::string& group, const std::string& name);

	void disbandGroup(const std::string &);
	void joinGroup(const std::string&);
	void leaveGroup(const std::string&);

	void createGroup(const std::string&);

	bool isJoinedGroup(const std::string&);
	bool isOwnedGroup(const std::string&);

	// -------- 客户端接收线程：支持长度头 + DES 解包 --------
	static void MessageReceiver(SOCKET sock);

	void SendMessage(SOCKET sock, const std::string& msg);

signals:
	void connect_res(const ConnectRes &);
	void login_res(const LoginRes &);
	void recv_sys(const std::string&);
	void recv_users(const std::string&);
	void recv_private_msg(const std::string &name, const std::string &msg);
	void recv_groups(const std::string&);
	void recv_group_msg(const std::string& group, const std::string& name, const std::string& msg);
	void recv_public_msg(const std::string& name, const std::string& msg);
	void recv_members(const std::string&);
    void recv_muted(const std::string&);
    void deleteUserRes(const std::string&);
    void assignRes(const std::string&);
	void recv_kick_res(const std::string&);
	void recv_kicked(const std::string&);
	void recv_mute_res(const std::string&);
	void recv_unmute_res(const std::string&);
	void recv_new_member(const std::string&);
	void recv_reduce_member(const std::string&);

	void recv_disband_res(const std::string&);
	void recv_join_res(const std::string&);
	void recv_leave_res(const std::string&);

	void recv_create_res(const bool &, const std::string &);

    void recv_group_disbanded(const std::string&);
    void muted_info(const std::string&);

private:
	static Client* m_instance;
	static std::atomic<bool> isRunning;
	static ClientState clientState;

	SOCKET connectSock;
};

#endif
