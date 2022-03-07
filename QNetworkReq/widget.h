#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QLineEdit *_ui_line_url = nullptr;
    QPushButton *_ui_btn_req = nullptr;
    QPlainTextEdit *_ui_txt_res = nullptr;
    QNetworkAccessManager *_net_mgr = nullptr;

    void onClickBtnReq();
    void onNetFinish();
};
#endif // WIDGET_H
