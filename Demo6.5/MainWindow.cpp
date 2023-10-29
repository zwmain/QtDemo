#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::uiMainWid)
{
    ui->setupUi(this);
    setWindowTitle(MainWindow::tr("羽飞的主页"));

    connect(ui->uiSearchBtn, &QPushButton::clicked, this, &MainWindow::onClickSearch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClickSearch()
{
    QString txt = ui->uiLineEdit->text();
    if (txt.isEmpty()) {
        QFile doc { ":/README.md" };
        bool isOk = doc.open(QIODevice::ReadOnly);
        if (!isOk) {
            ui->uiTxtEdit->setPlainText(MainWindow::tr("文件读取错误"));
            return;
        }
        txt = doc.readAll();
        ui->uiTxtEdit->setPlainText(txt);
    }
}
