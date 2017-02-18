#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

// 运算类型
enum ActionFlag{
    NoAction, // 没用运算符
    AddtionFlag, // 加
    SubtractionFlag, // 减
    MultiplicationFlag, // 乘
    DivisionFlag // 除
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ActionFlag currentAction; // 当前进行的运算类型
    QString lastNumber; // 上一个值
    QString currentNumber; // 当前值
    bool isEmpty; // // true 当前没有运算符；false 当前有运算符

    QDialog *selectDialog;
    QComboBox *selectCombo;
public slots:
    void clear();
    void actionChanged();
    void inputNumber();
    void displayNumber();
    void negationClicked();
    void percentageClicked();
    void decimalPointClicked();
    void evaluationClicked();

    void aboutApp();

    void unitSelect();
    void unitCalc();
};

#endif // MAINWINDOW_H
