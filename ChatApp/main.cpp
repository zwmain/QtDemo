#include "UiMain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    UiMain ui_main;
    ui_main.show();

    return app.exec();
}
