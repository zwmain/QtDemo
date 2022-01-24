#include "NetworkReqUi.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

NetworkReqUi::NetworkReqUi() : QWidget(nullptr)
{
    // 初始化UI
    initUi();
    // 初始化事件
    initEvent();
}

void NetworkReqUi::initUi()
{
    // 初始化URL输入框和请求按钮
    // 注意：这里的Layout不能指定parent
    _ui_hlay_req = new QHBoxLayout;
    _ui_line_url = new QLineEdit(this);
    _ui_btn_req = new QPushButton("请求", this);
    _ui_hlay_req->addWidget(_ui_line_url);
    _ui_hlay_req->addWidget(_ui_btn_req);

    // 初始化结果展示文本框
    // 注意：这里的Layout不能指定parent
    _ui_vlay_res = new QVBoxLayout;
    _ui_txt_res = new QPlainTextEdit(this);
    _ui_vlay_res->addWidget(_ui_txt_res);

    // 添加主布局
    // 一个Widget只能指定一个Layout
    // 其他Layout需要作为主Layout的子Layout存在
    // 不用手动释放
    _ui_vlay_ui = new QVBoxLayout(this);
    _ui_vlay_ui->addLayout(_ui_hlay_req);
    _ui_vlay_ui->addLayout(_ui_vlay_res);
    this->setLayout(_ui_vlay_ui);

    // 窗口大小
    this->resize(800, 600);
}

void NetworkReqUi::initEvent()
{
    this->connect(_ui_btn_req, &QPushButton::clicked, [this]()
                  { this->onClickBtnReq(); });
}

void NetworkReqUi::onClickBtnReq()
{
    QString urlStr = _ui_line_url->text();
    QRegularExpression regUrl("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$");
    QRegularExpressionMatch match = regUrl.match(urlStr);
    bool matFlag = match.hasMatch();
    if (!matFlag)
    {
        _ui_txt_res->setPlainText("请输入一个链接");
        return;
    }
    _ui_txt_res->clear();
    _ui_txt_res->appendPlainText(QString("开始请求：") + urlStr);
}
