#include <QWidget>

namespace Ui {
class UiMainWindow;
}

class MainWindow : public QWidget {
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::UiMainWindow* ui;
};
