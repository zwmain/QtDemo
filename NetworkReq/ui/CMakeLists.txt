cmake_minimum_required(VERSION 3.16)

project(NetworkReqUi)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Network)

add_library(${PROJECT_NAME} SHARED inc/NetworkReqUi.h src/NetworkReqUi.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets Qt6::Network)
