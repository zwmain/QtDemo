cmake_minimum_required(VERSION 3.16)

project(NoBorderAndShadow)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 提供Qt编译支持
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/Qt6/6.2.3/gcc_64")
