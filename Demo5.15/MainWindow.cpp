#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::UiMainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}
