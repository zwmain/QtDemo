#include "widget.h"
#include "./ui_widget.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QNetworkRequest>
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    _ui_line_url=ui->ui_url;
    _ui_btn_req=ui->ui_btn_req;
    _ui_txt_res=ui->ui_txt_res;
    _net_mgr=new QNetworkAccessManager(this);

    connect(_ui_btn_req,&QPushButton::clicked,this,&Widget::onClickBtnReq);
    connect(_net_mgr, &QNetworkAccessManager::finished, this, &Widget::onNetFinish);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onClickBtnReq()
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
    _net_mgr->get(QNetworkRequest(urlStr));
}

void Widget::onNetFinish()
{
    _ui_txt_res->appendPlainText("请求结束");
}

