#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QWidget>

namespace Ui {
class uiMainWid;
} // namespace Ui

class MainWindow : public QWidget {
    Q_OBJECT;

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void onClickSearch();

private:
    Ui::uiMainWid* ui = nullptr;
};

#endif
