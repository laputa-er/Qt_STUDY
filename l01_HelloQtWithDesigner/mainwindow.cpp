#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label = ui->label;
    ui->label->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// pushButton 被点击时，显示 label。
void MainWindow::on_pushButton_clicked()
{
    ui->label->show();
}
