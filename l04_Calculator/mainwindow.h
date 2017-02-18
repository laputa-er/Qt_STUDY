#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *bar1;
    QLabel *bar2;
public slots:
    void saveActionClicked();
    void showMessage(const QString &message, int timeOut);
};

#endif // MAINWINDOW_H
