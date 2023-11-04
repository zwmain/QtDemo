#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::UiMainWindow)
{
    ui->setupUi(this);

    connect(ui->uiSearchBtn, &QPushButton::clicked, this, &MainWindow::onSearch);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onSearch()
{
    QString txt = ui->uiLineEdit->text();
    if (txt.isEmpty()) {
        QFile f(":/README.md");
        bool isOk = f.open(QIODevice::ReadOnly);
        if (!isOk) {
            ui->plainTextEdit->appendPlainText("打开文件失败");
            return;
        }
        txt = f.readAll();
        ui->plainTextEdit->setPlainText(txt);
    }
}
