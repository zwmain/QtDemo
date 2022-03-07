cmake_minimum_required(VERSION 3.16)

project(main)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE NetworkReqUi)
