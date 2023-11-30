# Qt5 CMake环境配置





## 参考

[Qt5文档](https://doc.qt.io/qt-5/cmake-manual.html)


## 配置可视化调试


### 使用GlobalVisualizersDirectory



Windows下

```txt
C:\Users\YourName\.vscode\extensions\ms-vscode.cpptools-1.18.5-win32-x64\debugAdapters\vsdbg\bin\Visualizers\
```

Linux下

```txt
~\.vscode\extensions\ms-vscode.cpptools-1.18.5-win32-x64\debugAdapters\vsdbg\bin\Visualizers\
```

打开目录可以发现，里面已经存在了一些natvis文件

![natvis](img/01.png)
借用EveryThing等工具，搜索`qt5.natvis`、`qt6.natvis`、`STL.natvis`等文件，复制到这个文件夹内

### visualizerFile

配置`visualizerFile`参数，natvis文件只能指定一个

```json
{
    "cmake.debugConfig": {
        "visualizerFile": "${workspaceFolder}/qt5.natvis"
    }
}
```

这个参数本来属于launch.json，因为我使用的是cmake插件，所以配置的是cmake

lanuch.json应该参考下面的代码，其实是一样的，而且还可以多配置一个`showDisplayString`

```json
{
  "name": "C++ Launch (Windows)",
  "type": "cppvsdbg",
  "request": "launch",
  "program": "C:\\app1\\Debug\\app1.exe",
  "symbolSearchPath": "C:\\Symbols;C:\\SymbolDir2",
  "externalConsole": true,
  "logging": {
    "moduleLoad": false,
    "trace": true
  },
  "visualizerFile": "${workspaceFolder}/my.natvis",
  "showDisplayString": true
}

```

### 效果展示

可以看到`QString`这样的类型已经正确显示

![QString](img/02.png)


