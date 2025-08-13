cmake_minimum_required(VERSION 3.20)
project(Server_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含ClientUI头文件目录和Qt头文件
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../ClientUI
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
)

# 配置预编译头文件 (必须在add_executable之后)
target_precompile_headers(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ClientUI/stdafx.h)

# 添加可执行文件
add_executable(server
    Server.cpp
    DES_s.cpp
    Server.h
    DES_s.h
    ../ClientUI/stdafx.cpp
)

# 链接库
target_link_libraries(server 
    Qt6::Core
    Qt6::Widgets
    ws2_32
)
