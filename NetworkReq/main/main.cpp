#include "NetworkReqUi.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    NetworkReqUi ui;
    ui.show();

    return app.exec();
}
