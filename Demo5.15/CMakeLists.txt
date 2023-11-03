cmake_minimum_required(VERSION 3.18)
project("Demo" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "E:\\ProgramFiles\\Qt\\5.15.2\\msvc2019_64;${CMAKE_PREFIX_PATH}")
# set(Qt5_DIR "D:\\ProgramFiles\\Qt\\5.15.2\\5.15\\msvc_2015_64\\lib\\cmake\\Qt5")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_INCLUDE)

find_package(Qt5 COMPONENTS Core Widgets LinguistTools REQUIRED)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    MainWindow.h
    MainWindow.cpp
    MainWindow.ui
    resources.qrc
)

target_include_directories(${PROJECT_NAME} PUBLIC ${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC Qt::Core Qt::Widgets)
