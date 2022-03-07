#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
// 这里必须使用QtNetwork/前缀
// 否则编译无法通过
#include <QtNetwork/QNetworkAccessManager>

class NetworkReqUi : public QWidget
{
public:
    NetworkReqUi();
    ~NetworkReqUi() = default;

private:
    QLineEdit *_ui_line_url = nullptr;
    QPushButton *_ui_btn_req = nullptr;
    QPlainTextEdit *_ui_txt_res = nullptr;
    QHBoxLayout *_ui_hlay_req = nullptr;
    QVBoxLayout *_ui_vlay_res = nullptr;
    QVBoxLayout *_ui_vlay_ui = nullptr;
    QNetworkAccessManager *_net_mgr = nullptr;

    void initUi();
    void initEvent();
    void initNetwork();

    void onClickBtnReq();
    void onNetFinish();
};
