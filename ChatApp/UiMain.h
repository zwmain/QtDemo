#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSplitter>
#include <QLabel>
#include <QLineEdit>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class UiMain : public QWidget
{
public:
    UiMain(QWidget *parent = nullptr);
    ~UiMain();

private:
    // UI
    QVBoxLayout *_ui_lay_main = nullptr;
    QWidget *_ui_wid_cfg = nullptr;
    QGridLayout *_ui_lay_cfg = nullptr;
    QLabel *_ui_lab_host = nullptr;
    QLabel *_ui_lab_port = nullptr;
    QLineEdit *_ui_lin_host = nullptr;
    QLineEdit *_ui_lin_port = nullptr;
    QPushButton *_ui_btn_cfg = nullptr;
    QSplitter *_ui_sp_main = nullptr;
    QListWidget *_ui_list_usr = nullptr;
    QSplitter *_ui_sp_txt = nullptr;
    QTextEdit *_ui_txt_input = nullptr;
    QWidget *_ui_wid_input = nullptr;
    QVBoxLayout *_ui_lay_input = nullptr;
    QTextEdit *_ui_txt_display = nullptr;
    QPushButton *_ui_btn_send = nullptr;

    // TCP
    QTcpServer *_server = nullptr;
    QTcpSocket *_sock = nullptr;

    // Event function
    void onAcceptError(QAbstractSocket::SocketError socketError);
    void onNewConnection();
};
