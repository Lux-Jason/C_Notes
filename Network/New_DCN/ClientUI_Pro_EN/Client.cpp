//Client.cpp
#include "Client.h"

Client* Client::m_instance = nullptr;
std::atomic<bool> Client::isRunning = true;
ClientState Client::clientState;


Client::Client()
{
	qRegisterMetaType<LoginRes>("LoginRes");
	qRegisterMetaType<std::string>("std::string");
}

Client::~Client()
{

}

Client* Client::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Client;
    }

    return m_instance;
}

int Client::start(const std::string& addr, const int& port)
{
	WSADATA wsaData;
	connectSock = INVALID_SOCKET;
	sockaddr_in serverAddr{};

	// 初始化Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cerr << "WSAStartup 失败: " << WSAGetLastError() << std::endl;
		return 1;
	}

	// 创建套接字
	if ((connectSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		std::cerr << "创建套接字失败: " << WSAGetLastError() << std::endl;
		WSACleanup();
		return 1;
	}

	// 设置服务器地址
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	if (inet_pton(AF_INET, addr.c_str(), &serverAddr.sin_addr) <= 0) {
		std::cerr << "地址解析失败: " << addr << std::endl;
		closesocket(connectSock);
		WSACleanup();
		return 1;
	}

	// 连接服务器
	if (::connect(connectSock, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
		std::cerr << "连接服务器失败: " << WSAGetLastError() << std::endl;
		closesocket(connectSock);
		WSACleanup();
		emit connect_res(ConnectRes::CONNECT_FALSE);
		return 1;
	}

	// 初始化DES加密模块
	if (des_init(0) == 0) { // 标准DES模式
		std::cerr << "DES加密模块初始化失败" << std::endl;
		closesocket(connectSock);
		WSACleanup();
		return 1;
	}
	des_set_key((char*)"mykey12"); // 设置8字节预共享密钥

	std::cout << "已安全连接到服务器 " << addr << ":" << port
		<< " [DES加密已启用]" << std::endl;

	// 启动接收线程
	std::thread receiverThread(MessageReceiver, connectSock);
	receiverThread.detach();

	emit connect_res(ConnectRes::CONNECT_SUCCESS);

    return 0;
}

void Client::stop()
{
	isRunning = false;

	// 清理流程
	std::cout << "\n正在终止连接..." << std::endl;
	shutdown(connectSock, SD_SEND);  // 优雅关闭发送通道
	closesocket(connectSock);

	// 释放DES资源
	des_done();

	// 清理Winsock
	WSACleanup();

	std::cout << "安全连接已关闭，客户端已退出" << std::endl;
}

void Client::HandleInput()
{
	SOCKET sock = connectSock;
	std::string input;
	PrintHelp();

	while (isRunning) {
		std::cout << "输入命令 (?查看帮助): ";
		std::getline(std::cin, input);

		if (input.empty()) continue;

		if (input[0] == '/') {
			size_t space = input.find(' ');
			std::string cmd = input.substr(1, space - 1);
			std::string args = (space != std::string::npos) ? input.substr(space + 1) : "";

			if (cmd == "login") {
			}
			else if (cmd == "unmute") {
			}
		}
	}
}

void Client::PrintHelp()
{
	std::cout << "\n可用命令：\n"
		<< "/login <用户名>        - 登录/更改昵称\n"
		<< "/create <群组名>       - 创建新群组\n" // 添加创建群组命令
		<< "/kick <群组名> <用户名> - 群主踢人\n"
		<< "/disband <群组名>       - 群主解散群组\n"
		<< "/mute <群组名> <用户名> - 群主禁言群成员\n"
		<< "/unmute <群组名> <用户名> - 群主解除禁言\n"
		<< "/join <群组名>         - 加入群组\n"
		<< "/leave <群组名>        - 离开群组\n"
		<< "/members <群组名>     - 查看群组成员\n"
		<< "/muted <群组名>       - 查看禁言用户\n"
		<< "/list                 - 列出在线用户\n"
		<< "/listgroups           - 列出所有可用群组\n" // 添加列出群组命令
		<< "/private <用户> <消息> - 私聊消息\n"
		<< "/group <群组> <消息>   - 群组消息\n"
		<< "/public <消息>         - 广播消息\n"
		<< "/exit                 - 退出程序\n"
		<< "/help                 - 显示帮助\n";
}

void Client::login(const std::string& usrName)
{
	SendMessage(connectSock, "LOGIN|" + usrName + "|-");
}

void Client::listUser()
{
	SendMessage(connectSock, "LIST|USERS|-");
}

void Client::listGroup()
{
	SendMessage(connectSock, "LIST|GROUPS|-");
}

void Client::sendChat(const std::string& to, const std::string& msg)
{
	SendMessage(connectSock, "PRIVATE|" + to + "|" + msg);
}

void Client::sendGroupChat(const std::string& to, const std::string& msg)
{
	SendMessage(connectSock, "GROUP|" + to + "|" + msg);
}

void Client::sendPublicChat(const std::string& msg)
{
	SendMessage(connectSock, "PUBLIC|-|" + msg);
}

void Client::listMembers(const std::string& group)
{
	SendMessage(connectSock, "MEMBERS|" + group + "|-");
}

void Client::listMuted(const std::string& group)
{
	SendMessage(connectSock, "MUTED|" + group + "|-");
}

void Client::kick(const std::string& group, const std::string& name)
{
	SendMessage(connectSock, "KICK|" + group + "|" + name);
}

void Client::mute(const std::string& group, const std::string& name)
{
	SendMessage(connectSock, "MUTE|" + group + "|" + name);
}

void Client::unmute(const std::string& group, const std::string& name)
{
	SendMessage(connectSock, "UNMUTE|" + group + "|" + name);
}

void Client::disbandGroup(const std::string &group)
{
	SendMessage(connectSock, "DISBAND|" + group + "|-");

	// 本地清除群组信息
	auto it1 = std::find(clientState.ownedGroups.begin(),
		clientState.ownedGroups.end(), group);
	if (it1 != clientState.ownedGroups.end())
		clientState.ownedGroups.erase(it1);

	auto it2 = std::find(clientState.joinedGroups.begin(),
		clientState.joinedGroups.end(), group);
	if (it2 != clientState.joinedGroups.end())
		clientState.joinedGroups.erase(it2);
}

void Client::joinGroup(const std::string &group)
{
	SendMessage(connectSock, "JOIN|" + group + "|-");
}

void Client::leaveGroup(const std::string &group)
{
	SendMessage(connectSock, "LEAVE|" + group + "|-");
}

void Client::createGroup(const std::string &group)
{
	SendMessage(connectSock, "CREATE|" + group + "|-");
}

bool Client::isJoinedGroup(const std::string &group)
{
	if (std::find(clientState.joinedGroups.begin(),
		clientState.joinedGroups.end(), group) != clientState.joinedGroups.end())
	{
		return true;
	}

	return false;
}

bool Client::isOwnedGroup(const std::string &group)
{
	if (std::find(clientState.ownedGroups.begin(),
		clientState.ownedGroups.end(), group) != clientState.ownedGroups.end())
	{
		return true;
	}

	return false;
}

void Client::MessageReceiver(SOCKET sock)
{
	std::vector<char> inBuf;               // 原始收包缓冲区
	std::vector<char> plainBuf;            // 解密后明文
	char tmp[BUFFER_SIZE];

	auto needMore = [&](void) -> bool {
		int n = recv(sock, tmp, BUFFER_SIZE, 0);
		if (n <= 0) {
			if (n == SOCKET_ERROR)
				std::cerr << "\n接收错误: " << WSAGetLastError() << std::endl;
			isRunning = false;
			return false;                  // 连接关闭
		}
		inBuf.insert(inBuf.end(), tmp, tmp + n);
		return true;
	};

	while (isRunning)
	{
		/*------------------- ① 解析 4 字节明文长度头 -------------------*/
		while (inBuf.size() < 4 && needMore()) {}
		if (inBuf.size() < 4) break;       // 断线

		uint32_t L;
		memcpy(&L, inBuf.data(), 4);
		L = ntohl(L);                      // 明文长度

		/*------------------- ② 计算需要的加密字节数 -------------------*/
		size_t pad = 8 - (L % 8);
		if (pad == 0) pad = 8;
		size_t encLen = L + pad;           // 密文总长度

		/*------------------- ③ 收满整条密文 -------------------*/
		while (inBuf.size() < 4 + encLen && needMore()) {}
		if (inBuf.size() < 4 + encLen) break;   // 断线

		/*------------------- ④ 解密整条消息 -------------------*/
		plainBuf.clear();
		for (size_t off = 4; off < 4 + encLen; off += 8) {
			char blk[8];
			memcpy(blk, inBuf.data() + off, 8);
			des_decrypt(blk);
			plainBuf.insert(plainBuf.end(), blk, blk + 8);
		}
		inBuf.erase(inBuf.begin(), inBuf.begin() + 4 + encLen); // 移除已处理字节

		/*------------------- ⑤ 去除 PKCS#7 填充 -------------------*/
		if (plainBuf.empty()) continue;    // 防御性检查
		size_t realLen = plainBuf.size() - static_cast<unsigned char>(plainBuf.back());
		if (realLen > plainBuf.size()) continue; // 填充异常，忽略
		std::string msg(plainBuf.data(), realLen);

		/*------------------- ⑥ 解析 "TYPE|FROM|CONTENT" 协议 -------------------*/
		size_t p1 = msg.find('|');
		size_t p2 = msg.find('|', p1 + 1);
		if (p1 == std::string::npos || p2 == std::string::npos) continue;

		std::string type = msg.substr(0, p1);
		std::string from = msg.substr(p1 + 1, p2 - p1 - 1);
		std::string content = msg.substr(p2 + 1);

		if (type == "PRIVATE") {
			std::cout << "\n[私聊来自 " << from << "]: " << content << std::endl;
			emit m_instance->recv_private_msg(from, content);
		}
		else if (type == "GROUP") {
			size_t separator = content.find('|');
			if (separator != std::string::npos) {
				std::string sender = content.substr(0, separator);
				std::string message = content.substr(separator + 1);
				std::cout << "\n[群组 " << from << " 来自 " << sender << "]: " << message << std::endl;
				emit m_instance->recv_group_msg(from, sender, message);
			}
		}
		else if (type == "PUBLIC") {
			std::cout << "\n[广播来自 " << from << "]: " << content << std::endl;
			emit m_instance->recv_public_msg(from, content);
		}
		else if (type == "USERS") {
			std::replace(content.begin(), content.end(), ',', '\n');
			std::cout << "\n在线用户列表:\n" << content << std::endl;
			emit m_instance->recv_users(content);
		}
		else if (type == "GROUPS") {
			std::replace(content.begin(), content.end(), ',', '\n');
			std::cout << "\n可用群组列表:\n" << content << std::endl;
			emit m_instance->recv_groups(content);
		}
		else if (type == "LOGIN") {
			std::cout << "\n[登录成功]: " << content << std::endl;
			clientState.username = content;
			emit m_instance->login_res(LoginRes::LOGIN_SUCCESS);
		}
		else if (type == "CREATE") {
			std::cout << "\n[创建群组成功]: " << content << std::endl;
			clientState.ownedGroups.push_back(content);
			clientState.joinedGroups.push_back(content);
			emit m_instance->recv_create_res(true, content);
		}
		else if (type == "JOIN") {
			std::cout << "\n[加入群组成功]: " << content << std::endl;
			if (std::find(clientState.joinedGroups.begin(),
				clientState.joinedGroups.end(), content) == clientState.joinedGroups.end()) {
				clientState.joinedGroups.push_back(content);
			}
			emit m_instance->recv_join_res(content);
		}
		else if (type == "LEAVE") {
			std::cout << "\n[离开群组成功]: " << content << std::endl;
			auto it = std::find(clientState.joinedGroups.begin(),
				clientState.joinedGroups.end(), content);
			if (it != clientState.joinedGroups.end()) {
				clientState.joinedGroups.erase(it);
			}
			auto it2 = std::find(clientState.ownedGroups.begin(),
				clientState.ownedGroups.end(), content);
			if (it2 != clientState.ownedGroups.end()) {
				clientState.ownedGroups.erase(it2);
			}
			emit m_instance->recv_leave_res(content);
		}
		else if (type == "SYS") {
			std::cout << "\n[系统消息]: " << content << std::endl;
			if (content == std::string("用户名已被使用，请选择其他名称"))
			{
				emit m_instance->login_res(LoginRes::NAME_UESED);
			}
			else if (content.find(std::string("你已解散群组")) != std::string::npos)
			{
				emit m_instance->recv_disband_res(content);
			}
			else if (content.find(std::string("群组名已存在")) != std::string::npos)
			{
				emit m_instance->recv_create_res(false, content);
			}
			else if (content.find(std::string("群组成员")) != std::string::npos)
			{
				emit m_instance->recv_members(content);
			}
			else if (content.find(std::string("群组成员")) != std::string::npos)
			{
				emit m_instance->recv_members(content);
			}
			else if (content.find(std::string("将")) != std::string::npos 
				&& content.find(std::string("踢出")) != std::string::npos)
			{
				emit m_instance->recv_kick_res(content);
			}
			else if (content.find(std::string("被")) != std::string::npos
				&& content.find(std::string("踢出")) != std::string::npos)
			{
				emit m_instance->recv_kicked(content);
			}
            else if (content.find(std::string("将")) != std::string::npos
                && content.find(std::string("解除禁言")) != std::string::npos)
            {
                emit m_instance->recv_unmute_res(content);
            }
			else if (content.find(std::string("将")) != std::string::npos
				&& content.find(std::string("禁言")) != std::string::npos)
			{
				emit m_instance->recv_mute_res(content);
			}
            else if (content.find(std::string("加入了群组")) != std::string::npos)
			{
				emit m_instance->recv_new_member(content);
			}
			else if (content.find(std::string("退出群组")) != std::string::npos)
			{
				emit m_instance->recv_reduce_member(content);
			}
			else if (content.find(std::string("被群主移出群组")) != std::string::npos)
			{
				emit m_instance->recv_reduce_member(content);
			}
            else if (content.find(std::string("已被群主解散")) != std::string::npos)
            {

                emit m_instance->recv_group_disbanded(content);
            }
            else if (content.find(std::string("你已被群主禁言，无法发言")) != std::string::npos)
            {

                emit m_instance->muted_info(content);
            }
			else
			{
				emit m_instance->recv_sys(content);
			}
		}
		else if (type == "MUTED") {
			std::cout << "\n[群组 " << from << " 的禁言成员]:\n" << content << std::endl;
			emit m_instance->recv_muted(content);
		}

		std::cout << "输入命令 (?查看帮助): ";
		std::cout.flush();
	}
}

void Client::SendMessage(SOCKET sock, const std::string& msg)
{
	// --- 1. PKCS#7 填充 ---
	size_t pad = 8 - (msg.size() % 8);
	if (pad == 0) pad = 8;
	std::string padded = msg + std::string(pad, static_cast<char>(pad));

	// --- 2. 加密 ---
	std::vector<char> enc;
	enc.reserve(padded.size());
	for (size_t i = 0; i < padded.size(); i += 8) {
		char blk[8]; memcpy(blk, padded.data() + i, 8);
		des_encrypt(blk);
		enc.insert(enc.end(), blk, blk + 8);
	}

	// --- 3. 带 4 字节长度头发送 ---
	uint32_t L = htonl(static_cast<uint32_t>(msg.size()));  // 明文长度
	send(sock, reinterpret_cast<char*>(&L), 4, 0);
	send(sock, enc.data(), static_cast<int>(enc.size()), 0);
}




