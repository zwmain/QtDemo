# Qt6.5 CMake项目配置

参考[Qt 安装文档](https://doc.qt.io/qt-6.5/linux.html)
参考[Qt CMake文档](https://doc.qt.io/qt-6.5/cmake-get-started.html)

Qt CMake配置与版本关联度比较高，不过Qt6.5以后的版本应该差不多

但是Qt6.5之前的配置方法可能就不同了，比如`qt_standard_project_setup()`可能就是不可用的

## 配置Qt路径

在Qt安装后，Qt并没有被自动添加到系统环境下

设置CMake的`CMAKE_PREFIX_PATH`

```cmake
set(CMAKE_PREFIX_PATH "/opt/Qt/6.5.2/gcc_64;${CMAKE_PREFIX_PATH}")
```

这个目录为Qt编译器目录，是`bin`、`include`、`modules`目录所在的目录

## 设置C++版本

Qt6是基于C++17构建的，所以需要设置C++版本

```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

## 获取Qt库

使用`find_package`函数，具体格式如下

```cmake
find_package(Qt6 REQUIRED COMPONENTS LinguistTools Core Widgets)
```

- LinguistTools，翻译工具，需要启用多语言的会用到这个库，提供了CMake配置ts文件的工具，不需要链接
- Core，Qt的Core库，提供了头文件和库列表，需要链接
- Widgets，Qt的Widgets库，`QWidget`等类都在这个模块下，需要链接

## 设置Qt CMake通用配置

这一步是最重要的，也是最容易出问题的地方，需要用到`qt_standard_project_setup()`

这个函数在Qt6.3才被引入，更早的版本都没法使用这个函数

使用时只要添加这个函数到CMake里面即可

```cmake
qt_standard_project_setup()
```

## 配置源代码和UI文件

在项目里添加源文件和头文件，以及对应的UI文件，项目结构如下

```txt
.
├── CMakeLists.txt
├── main.cpp
├── MainWindow.cpp
├── MainWindow.h
├── MainWindow.ui
└── README.md
```

Qt提供了一个`qt_add_executable`函数，用法和CMake的`add_executable`一致

ui文件可以和普通代码文件一样，直接添加，Qt提供的工具，告诉了CMake这些UI文件该怎么处理

```cmake
qt_add_executable(
    ${PROJECT_NAME}
    main.cpp
    MainWindow.h
    MainWindow.cpp
    MainWindow.ui
)
```

到这一步为止，一个基本的Qt程序就基本完成了，只要链接对应的库就可以运行

没有翻译文件，也没有资源文件

> 注意：ui文件会被UIC生成一个头文件；
> 但是这个头文件在构建项目的时候不会生成；
> 只有在编译的时候才会生成；
> 因此，当在cpp文件中添加头文件时报错，不要担心；
> 编译一次就可以解决；

## 添加资源文件

如果程序不需要资源文件，可以直接忽略

在Qt下，这个资源文件**不要**自己添加，只要在CMake中配置就行

CMake会调用Qt工具，自动生成`qrc`文件

qrc中需要添加的文件路径，前缀等，都在CMake中配置

详细用法，可以参考Qt文档[qt_add_resources](https://doc.qt.io/qt-6.5/qt-add-resources.html)

该模块依赖与`Core`模块

```cmake
find_package(Qt6 REQUIRED COMPONENTS Core)
```

基础用法如下：

```cmake
qt_add_resources(
    ${PROJECT_NAME}
    ${PROJECT_NAME} PREFIX "/" FILES
    README.md
)
```

第一个`${PROJECT_NAME}`是目标项目，第二个`${PROJECT_NAME}`是文件名

`README.md`就是要添加的文件，因为该文件和CMakeLists文件在同一个文件夹下，所以直接写了文件名

可以在后面添加更多的文件

## 添加翻译文件

翻译文件以`ts`结尾

在CMake中，**不要**创建ts文件，CMake会自动生成

添加翻译文件会用到`qt_add_translations`函数

该函数需要依赖`LinguistTools`模块

```cmake
find_package(Qt6 REQUIRED COMPONENTS LinguistTools)
```

```cmake
qt_add_translations(
    ${PROJECT_NAME}
    TS_FILES
    "${PROJECT_NAME}_en.ts"
    "${PROJECT_NAME}_fr.ts"
)
```

第一个参数是添加目标，然后给一个`TS_FILES`标记，表示后面的都是ts文件了

可以一次添加多个ts文件

具体用法可以参考Qt文档：[qt_add_translations](https://doc.qt.io/qt-6.5/qtlinguist-cmake-qt-add-translations.html#qt6-add-translations)

这个函数会在CMake项目里添加两个目标：`update_translations`、`release_translations`

就像`add_executable`添加出来的xxx目标一样

CMake和Qt是通过运行这两个目标的方式实现更新翻译文件的

可能会感到有点奇怪，但是这就是他们的实现机制，不要过多考虑

此时并没有ts文件，需要**单独**运行构建目标的命令

运行下面的命令更新ts文件

```cmake
$ cmake --build . --target update_translations
```

再运行下面的命令生成qm文件

```cmake
$ cmake --build . --target release_translations
```

**注意**：这两个目标必须按顺序单独执行，不能build all，否则ts文件会生成异常

最后，生成的qm文件被自动添加到了qrc资源文件里面，前缀是`/i18n`


## 添加头文件目录和链接库

这部分主要是头文件目录的指定

在模块被发现后，会自动设置一些变量，头文件目录就是其中一个

比如`Widgets`模块，其头文件目录就是`${Qt6Widgets_INCLUDE_DIRS}`

```cmake
# 添加头文件目录，实际测试中，不添加好像也没问题
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt6Widgets_INCLUDE_DIRS})
# 链接Qt相关库，其它Qt库也都是这种格式
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)
```

## 设置目标属性

主要在Windows和MACOS下起作用

目的是禁用命令行窗口

```cmake
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
```

## 问题及解决

首先，安装Qt的时候就应该安装相关依赖

```shell
sudo apt-get install build-essential libgl1-mesa-dev
```

```txt
[cmake] -- Could NOT find XKB (missing: XKB_LIBRARY XKB_INCLUDE_DIR) (Required is at least version "0.5.0")
[cmake] -- Could NOT find WrapVulkanHeaders (missing: Vulkan_INCLUDE_DIR)
```

使用以下命令安装相关依赖

```shell
sudo apt install libxkbcommon-dev libvulkan-dev
```

## 项目文件结构

```txt
.
├── build
├── CMakeLists.txt
├── Demo_en.ts
├── Demo_fr.ts
├── main.cpp
├── MainWindow.cpp
├── MainWindow.h
├── MainWindow.ui
└── README.md
```

其中ts文件是自动生成在当前目录的

qrc和qm文件以及ui的头文件都生成在了build目录内

## 源码

### CMakeLists.txt

```cmake
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

# 设置应用程序属性，主要在Windows和MACOS下起作用
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


```

### MainWindow.h

```cpp
#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QWidget>

namespace Ui {
class uiMainWid;
} // namespace Ui

class MainWindow : public QWidget {
    Q_OBJECT;

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void onClickSearch();

private:
    Ui::uiMainWid* ui = nullptr;
};

#endif

```

### MainWindow.cpp

```cpp
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::uiMainWid)
{
    ui->setupUi(this);
    setWindowTitle(MainWindow::tr("羽飞的主页"));

    connect(ui->uiSearchBtn, &QPushButton::clicked, this, &MainWindow::onClickSearch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClickSearch()
{
    QString txt = ui->uiLineEdit->text();
    if (txt.isEmpty()) {
        QFile doc { ":/README.md" };
        bool isOk = doc.open(QIODevice::ReadOnly);
        if (!isOk) {
            ui->uiTxtEdit->setPlainText(MainWindow::tr("文件读取错误"));
            return;
        }
        txt = doc.readAll();
        ui->uiTxtEdit->setPlainText(txt);
    }
}

```


