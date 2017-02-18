#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDialogButtonBox>
#include <QGroupBox>
#include<QMessageBox>
#include <QComboBox>
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentAction(NoAction),
    isEmpty(true)
{
    ui->setupUi(this);

    // 菜单栏禁用最大化按钮
    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint|Qt::WindowMinimizeButtonHint);

    /*
     * 将按钮的操作关联到槽
     */
    connect(ui->btnClear, SIGNAL(clicked(bool)), this, SLOT(clear())); // 清空
    connect(ui->btnNegativity, SIGNAL(clicked(bool)), this, SLOT(negationClicked())); // 正/负
    connect(ui->btnPercentage, SIGNAL(clicked(bool)), this, SLOT(percentageClicked())); // %
    connect(ui->btnDecimalPoint, SIGNAL(clicked(bool)), this, SLOT(decimalPointClicked())); // .
    connect(ui->btnEvaluation, SIGNAL(clicked(bool)), this, SLOT(evaluationClicked())); // =

    connect(ui->btnAddtion, SIGNAL(clicked(bool)), this, SLOT(actionChanged())); // +
    connect(ui->btnSubtraction, SIGNAL(clicked(bool)), this, SLOT(actionChanged())); // -
    connect(ui->btnMultiplication, SIGNAL(clicked(bool)), this, SLOT(actionChanged())); // X
    connect(ui->btnDivision, SIGNAL(clicked(bool)), this, SLOT(actionChanged())); // /

    connect(ui->btnNum0, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum1, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum2, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum3, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum4, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum5, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum6, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum7, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum8, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));
    connect(ui->btnNum9, SIGNAL(clicked(bool)), this, SLOT(inputNumber()));

    /*
     * 菜单栏的菜单功能
     */
    connect(ui->actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // 关于 Qt
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(aboutApp())); // 关于
    connect(ui->actionUnitSelect, SIGNAL(triggered(bool)), this, SLOT(unitSelect())); // 单位转换->选择单位
}

MainWindow::~MainWindow()
{
    delete ui;
}

// AC 或 C 被点击
void MainWindow::clear()
{
    if (ui->btnClear->text() == "AC")
    {
        currentAction = NoAction;
        currentNumber = "0";
        lastNumber = "0";
        isEmpty = true;
    }
    else if (ui->btnClear->text() == "C")
    {
        currentNumber = "0";
        isEmpty = true;
        ui->btnClear->setText("AC");
    }
    displayNumber();
}

// + - X / 操作符被点击
void MainWindow::actionChanged()
{
    // 获取被点击的按钮对象
    QPushButton *button = qobject_cast<QPushButton *>(this->sender());
    if (button)
    {
       isEmpty = false;
       // +
       if(button == ui->btnAddtion)
       {
           currentAction = AddtionFlag;
           statusBar()->showMessage("选择了加法", 3000);
       }
       // -
       else if (button == ui->btnSubtraction)
       {
            currentAction = SubtractionFlag;
            statusBar()->showMessage("选择了减法", 3000);
       }
       // ×
       else if (button == ui->btnMultiplication)
       {
            currentAction = MultiplicationFlag;
            statusBar()->showMessage("选择了乘法", 3000);
       }
       // ÷
       else if (button == ui->btnDivision)
       {
            currentAction = DivisionFlag;
            statusBar()->showMessage("选择了除法", 3000);
       }
       else
       {
           currentAction = NoAction;
       }
    }
}

// 数字按钮被点击
void MainWindow::inputNumber()
{
    QPushButton *button = qobject_cast<QPushButton *>(this->sender());
    if (button)
    {
        // 用户输入了数字，清除键显示 C，表示可清空刚输入的操作数
        ui->btnClear->setText("C");

        // 有操作符(上一次点击的是操作符按钮)
        if(!isEmpty)
        {
            // 将第一个操作数的值赋值给 lastNumber
            lastNumber = currentNumber;
            // currentNumber 为第二个操作数做好准备
            currentNumber.clear();
            isEmpty = true;
        }

        /*
         * 如果当前显示屏中已经显示了0了,那么我们显然不应该在输入一个数字后让它变成0102这种,所以我们这时候要给显示屏的内容先清空,一样使用clear.
         */
        if(currentNumber == "0")
        {
            currentNumber.clear();
        }

        if(button == ui->btnNum0)
        {
            currentNumber.append("0");
            statusBar()->showMessage("输入了0", 3000);
        }
        else if(button == ui->btnNum1){
            currentNumber.append("1");
            statusBar()->showMessage("输入了1", 3000);
        }
        else if(button == ui->btnNum2){
            currentNumber.append("2");
            statusBar()->showMessage("输入了2", 3000);
        }
        else if(button == ui->btnNum3){
            currentNumber.append("3");
            statusBar()->showMessage("输入了3", 3000);
        }
        else if(button == ui->btnNum4){
            currentNumber.append("4");
            statusBar()->showMessage("输入了4", 3000);
        }
        else if(button == ui->btnNum5){
            currentNumber.append("5");
            statusBar()->showMessage("输入了5", 3000);
        }
        else if(button == ui->btnNum6){
            currentNumber.append("6");
            statusBar()->showMessage("输入了6", 3000);
        }
        else if(button == ui->btnNum7){
            currentNumber.append("7");
            statusBar()->showMessage("输入了7", 3000);
        }
        else if(button == ui->btnNum8){
            currentNumber.append("8");
            statusBar()->showMessage("输入了8", 3000);
        }
        else if(button == ui->btnNum9){
            currentNumber.append("9");
            statusBar()->showMessage("输入了9", 3000);
        }
        displayNumber();
    }
}

// 在显示屏上显示数字
void MainWindow::displayNumber()
{
    ui->label->setText(currentNumber);
}

// 正负切换按钮
void MainWindow::negationClicked()
{
    // 如果上一次按的的运算符按钮，或者当前数字被清空了
    if(!isEmpty || (currentNumber.size() == 0))
    {
        isEmpty = true;
        currentNumber = "0";
    }
    else
    {
        // 负数转为正数
        if(currentNumber.at(0) == '-')
        {
            currentNumber.remove(0, 1);
        }
        // 正数转为负数
        else
        {
            currentNumber.push_front("-");
        }
    }
    statusBar()->showMessage("符号变更", 3000);
    displayNumber();
}

// %
void MainWindow::percentageClicked()
{
    if(!isEmpty)
    {
        isEmpty = true;
        currentNumber = "0";
    }
    else
    {
        double number = currentNumber.toDouble() / 100.0;
        currentNumber = QString::number(number);
    }
    statusBar()->showMessage("百分比", 3000);
    displayNumber();
}

// .
void MainWindow::decimalPointClicked()
{
    if(!isEmpty)
    {
        currentNumber = "0.";
        isEmpty = true;
    }
    else if(currentNumber.indexOf(".") == -1)
    {
        currentNumber.push_back(".");
    }
    statusBar()->showMessage("输入了小数点", 3000);
    displayNumber();
}

// =
void MainWindow::evaluationClicked()
{
    if(currentAction == NoAction)
    {
        statusBar()->showMessage("请选择一个运算", 3000);
        return;
    }

    switch(currentAction)
    {
        case AddtionFlag:
        {
            currentNumber = QString::number(lastNumber.toDouble() + currentNumber.toDouble());
            break;
        }
        case SubtractionFlag:
        {
            currentNumber = QString::number(lastNumber.toDouble() - currentNumber.toDouble());
            break;
        }
        case MultiplicationFlag:
        {
            currentNumber = QString::number(lastNumber.toDouble() * currentNumber.toDouble());
            break;
        }
        case DivisionFlag:
        {
            currentNumber = QString::number(lastNumber.toDouble() / currentNumber.toDouble());
            break;
        }
        default:
                break;
    }
    statusBar()->showMessage("计算完成", 3000);
    currentAction = NoAction;
    displayNumber();
}

// 关于
void MainWindow::aboutApp()
{
    QMessageBox::about(this, "关于计算器", "此应用仅限于极客学院教学演示");
}

// 选择单位
void MainWindow::unitSelect()
{
    selectDialog = new QDialog(this);
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *displayLabel;

    // 设置对话框的大小
    selectDialog->resize(400, 150);

    buttonBox = new QDialogButtonBox(selectDialog);
    buttonBox->setGeometry(30, 100, 341, 32); // 相对父窗口的坐标和大小
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok); // 对话框添加两个按钮

    groupBox = new QGroupBox(selectDialog);
    groupBox->setGeometry(10, 10, 180, 80);
    groupBox->setTitle("要转换的数值");

    groupBox_2 = new QGroupBox(selectDialog);
    groupBox_2->setGeometry(210, 10, 180, 80);
    groupBox_2->setTitle("转换后的单位");

    displayLabel = new QLabel(ui->label->text(), groupBox);
    displayLabel->setGeometry(10, 40, 120, 16);

    selectCombo = new QComboBox(groupBox_2);
    selectCombo->setGeometry(10, 140, 120, 26);
    selectCombo->clear();
    selectCombo->insertItem(0, "米->厘米");
    selectCombo->insertItem(1, "米->平方米");

    // 对话框中点击 Cancel
    connect(buttonBox, SIGNAL(rejected()), selectDialog, SLOT(deleteLater()));
    // 对话框中点击 Ok
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(unitCalc()));

    selectDialog->exec();
}

// 单位换算
void MainWindow::unitCalc()
{
    switch(selectCombo->currentIndex())
    {
    // 米->厘米
    case 0:
        currentNumber = QString::number(currentNumber.toDouble() * 100);
        break;
    // 米->平方米
    case 1:
        currentNumber = QString::number(pow(currentNumber.toDouble(), 2));
    default:
        break;
    }
    selectDialog->deleteLater(); // 计算完成后关闭 selectDialog 并删除
    displayNumber();
}


