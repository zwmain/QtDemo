#include "UiMain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    UiMain w;
    w.show();

    return app.exec();
}
