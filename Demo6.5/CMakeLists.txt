cmake_minimum_required(VERSION 3.16)
project("Demo" VERSION 1.0.0 LANGUAGES CXX)

# 设置Qt路径
set(CMAKE_PREFIX_PATH "/opt/Qt/6.5.2/gcc_64;${CMAKE_PREFIX_PATH}")

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 寻找Qt6库以及其中各种模块
find_package(Qt6 REQUIRED COMPONENTS LinguistTools Core Widgets)
# Qt CMake通用设置
qt_standard_project_setup()

# 添加文件到应用程序，这是Qt提供的工具，因此ui文件也可以直接添加进去
# 需要注意，这个ui文件会生成一个ui_xxx.h的头文件
# 不过这个头文件需要在第一次编译之后才会生成，所以构建结束后找不到这个头文件是正常的
qt_add_executable(
    ${PROJECT_NAME}
    main.cpp
    MainWindow.h
    MainWindow.cpp
    MainWindow.ui
)

qt_add_resources(
    ${PROJECT_NAME}
    ${PROJECT_NAME} PREFIX "/" FILES
    README.md
)

qt_add_translations(
    ${PROJECT_NAME}
    TS_FILES
    "${PROJECT_NAME}_en.ts"
    "${PROJECT_NAME}_fr.ts"
)
# qt_add_lupdate(${PROJECT_NAME} TS_FILES "${PROJECT_NAME}_en.ts" "${PROJECT_NAME}_fr.ts")
# qt_add_lrelease(${PROJECT_NAME} TS_FILES "${PROJECT_NAME}_en.ts" "${PROJECT_NAME}_fr.ts")

# 添加头文件目录，实际测试中，不添加好像也没问题
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt6Widgets_INCLUDE_DIRS})
# 链接Qt相关库，其它Qt库也都是这种格式
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

add_dependencies(${PROJECT_NAME} update_translations release_translations)

# 设置应用程序属性，主要在Windows和MACOS下起作用
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

