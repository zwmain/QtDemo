#include "UiMain.h"

UiMain::UiMain(QWidget *parent) : QWidget(parent)
{
    this->resize(800, 600);

    _ui_lay_main = new QVBoxLayout(this);
    _ui_lay_main->setContentsMargins(1, 1, 1, 1);

    _ui_wid_cfg = new QWidget(this);
    _ui_wid_cfg->setSizePolicy(
        QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum));
    _ui_lay_cfg = new QGridLayout(_ui_wid_cfg);
    _ui_lay_cfg->setContentsMargins(0, 0, 0, 0);
    _ui_lay_main->addWidget(_ui_wid_cfg);

    _ui_lab_host = new QLabel("地址：", _ui_wid_cfg);
    _ui_lay_cfg->addWidget(_ui_lab_host, 0, 0, 1, 1);

    _ui_lin_host = new QLineEdit(_ui_wid_cfg);
    _ui_lay_cfg->addWidget(_ui_lin_host, 0, 1, 1, 1);

    _ui_lab_port = new QLabel("端口：", _ui_wid_cfg);
    _ui_lay_cfg->addWidget(_ui_lab_port, 0, 2, 1, 1);

    _ui_lin_port = new QLineEdit(_ui_wid_cfg);
    _ui_lay_cfg->addWidget(_ui_lin_port, 0, 3, 1, 1);

    _ui_btn_cfg = new QPushButton("连接", _ui_wid_cfg);
    _ui_lay_cfg->addWidget(_ui_btn_cfg, 0, 4, 1, 1);

    _ui_sp_main = new QSplitter(Qt::Orientation::Horizontal, this);
    _ui_lay_main->addWidget(_ui_sp_main);

    _ui_list_usr = new QListWidget(_ui_sp_main);

    _ui_sp_txt = new QSplitter(Qt::Orientation::Vertical, _ui_sp_main);

    _ui_txt_display = new QTextEdit(_ui_sp_txt);
    _ui_txt_display->setReadOnly(true);

    _ui_wid_input = new QWidget(_ui_sp_txt);
    _ui_lay_input = new QVBoxLayout(_ui_wid_input);
    _ui_lay_input->setContentsMargins(0, 0, 0, 0);
    _ui_lay_input->setSpacing(1);

    _ui_txt_input = new QTextEdit(_ui_wid_input);
    _ui_btn_send = new QPushButton("发送", _ui_wid_input);
    _ui_lay_input->addWidget(_ui_txt_input);
    _ui_lay_input->addWidget(_ui_btn_send);

    _server = new QTcpServer(this);
    bool is_success = false;
    quint16 port = 8848;
    while (!is_success && port < 10000)
    {
        is_success = _server->listen(QHostAddress("127.0.0.1"), port);
        ++port;
    }
    --port;

    if (is_success)
    {
        _ui_txt_display->append(QString("IP地址：%1").arg("127.0.0.1"));
        _ui_txt_display->append(QString("端口：%2").arg(port));
    }

    connect(_server, &QTcpServer::acceptError, this, &UiMain::onAcceptError);
    connect(_server, &QTcpServer::newConnection, this, &UiMain::onNewConnection);

    _sock = new QTcpSocket(this);
}

UiMain::~UiMain()
{
    if (_server && _server->isListening())
    {
        _server->close();
    }
}

void UiMain::onAcceptError(QAbstractSocket::SocketError socketError)
{
    // todo
}

void UiMain::onNewConnection()
{
    // todo
}
