#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QAction>
#include <QMenuBar>
#include <QTimer>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*  测试添加菜单(并添加一个动作) */
    // 创建动作(Save)
    QAction *newAction = new QAction("Save", this);

    newAction->setShortcut(QKeySequence::Save); // 设置快捷键
    newAction->setToolTip("Save"); // 设置提示
    newAction->setStatusTip("Save Now"); // 设置工具栏提示（鼠标悬浮时显示的提示内容）

    // 创建一个新菜单（New）
    QMenu *newMenu = menuBar()->addMenu("New"); // menuBar 是 继承自 QMainWindow 的方法

    // 将动作 Save 添加到菜单 New
    newMenu->addAction(newAction);

    // 关联动作的触发信号到槽
//    connect(newAction, &QAction::triggered, this, &MainWindow::saveActionClicked);
    // connect(newAction, SIGNAL(triggered(bool)), this, SLOT(savaActionClicked()));

    /* 测试给状态栏添加状态信息 */
    bar1 = new QLabel("Bar1");
    bar2 = new QLabel("Bar2");

    statusBar()->addWidget(bar1);
    statusBar()->addWidget(bar2, 1); // 填满余下的空间

    bar1->show(); // 一直显示

    showMessage("TestMsg", 3000); // bar2 显示 3s

    connect(newAction, &QAction::triggered, this, &MainWindow::openDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 动作被触发时关联的槽（关闭软件）
void MainWindow::saveActionClicked()
{
    qApp->quit();
}

// 测试状态栏（显示信息，并在指定时候后关闭）
void MainWindow::showMessage(const QString &message, int timeOut)
{
    bar2->setText(message);
    QTimer *timer = new QTimer;
    timer->singleShot(timeOut, bar2, SLOT(clear()));
}

// 新建并打开一个对话框
void MainWindow::openDialog()
{
    Dialog dialog;

    // 如果打开的对话框中，用户点击了确认
    if(dialog.exec() == QDialog::Accepted)
    {
        // 推出程序
        qApp->quit();
    }
}
