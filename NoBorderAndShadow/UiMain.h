#pragma once
#include <QWidget>

class UiMain : public QWidget
{
public:
    UiMain(QWidget *parent = nullptr);
    ~UiMain();

    // 通过重载鼠标事件函数实现拖拽
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPointF _mouse_pos; // 鼠标在窗口中的相对位置
};
