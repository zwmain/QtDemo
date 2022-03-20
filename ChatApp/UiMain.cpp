#include "UiMain.h"

UiMain::UiMain(QWidget *parent) : QWidget(parent)
{
    _ui_lay_main = new QVBoxLayout(this);
    _ui_lay_main->setContentsMargins(1, 1, 1, 1);

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
}

UiMain::~UiMain()
{
}
