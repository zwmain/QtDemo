#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>

class UiMain : public QWidget
{
public:
    UiMain(QWidget *parent = nullptr);
    ~UiMain();

private:
    // UI
    QListWidget *_ui_usr_list = nullptr;
    QTextEdit *_ui_txt_input = nullptr;
    QTextEdit *_ui_txt_display = nullptr;
    QPushButton *_ui_btn_send = nullptr;
};
