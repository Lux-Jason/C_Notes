cmake_minimum_required(VERSION 3.20)
project(ClientUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Widgets Network REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")
file(GLOB FORMS "*.ui")

add_executable(ClientUI
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
)

target_link_libraries(ClientUI PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)
