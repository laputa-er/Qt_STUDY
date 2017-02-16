#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label = ui->label;
    label->setText("Qt大法好！");

}

MainWindow::~MainWindow()
{
    delete ui;
}
