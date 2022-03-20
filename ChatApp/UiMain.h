#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSplitter>

class UiMain : public QWidget
{
public:
    UiMain(QWidget *parent = nullptr);
    ~UiMain();

private:
    // UI
    QVBoxLayout *_ui_lay_main = nullptr;
    QSplitter *_ui_sp_main = nullptr;
    QListWidget *_ui_list_usr = nullptr;
    QSplitter *_ui_sp_txt = nullptr;
    QTextEdit *_ui_txt_input = nullptr;
    QWidget *_ui_wid_input = nullptr;
    QVBoxLayout *_ui_lay_input = nullptr;
    QTextEdit *_ui_txt_display = nullptr;
    QPushButton *_ui_btn_send = nullptr;
};
