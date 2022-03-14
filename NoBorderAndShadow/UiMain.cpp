#include "UiMain.h"
#include <QMouseEvent>

UiMain::UiMain(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::WindowType::FramelessWindowHint);
}

UiMain::~UiMain()
{
}

void UiMain::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    // 获取鼠标相对于桌面左上角的位置-全局位置
    QPointF globalPos = event->globalPosition();
    // 计算窗口在桌面的位置
    QPointF widgetPos = globalPos - _mouse_pos;
    // 设置窗口位置
    this->move(widgetPos.toPoint());
}

void UiMain::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    // 获取鼠标相对于桌面左上角的位置-全局位置
    QPointF globalPos = event->globalPosition();
    // 获取当前窗口左上角在桌面中的位置-窗口位置
    QPointF widgetPos = this->geometry().topLeft();
    // 计算鼠标在窗口的相对位置
    // 鼠标相对窗口位置在移动过程中不变
    _mouse_pos = globalPos - widgetPos;
}

void UiMain::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
}
