#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

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

    void initUi();
};
