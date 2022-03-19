cmake_minimum_required(VERSION 3.16)

project(ChatApp)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 提供Qt编译支持
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 设置Qt路径
set(CMAKE_PREFIX_PATH "/opt/Qt/Qt6/6.2.3/gcc_64")

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(MY_HEADER
    UiMain.h
)

set(MY_SRC
    UiMain.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${MY_HEADER} ${MY_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)
