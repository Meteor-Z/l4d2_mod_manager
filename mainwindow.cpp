#include <QToolBar>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_open_action = new QAction(tr("&Open"), this);
    m_open_action->setShortcut(QKeySequence::Open);
    m_open_action->setStatusTip(tr("Open a file"));

    QMenu* file = menuBar()->addMenu(tr("关于"));

    file->addAction(m_open_action);



    QToolBar* tool_bar = addToolBar(tr("&File"));

    tool_bar->addAction(m_open_action);

    // 关于的建立起来
    QObject::connect(m_open_action, &QAction::triggered, this, &MainWindow::about_open);

}
void MainWindow::about_open() {
    QMessageBox::information(nullptr, tr("你好"), tr("你好"));
}
MainWindow::~MainWindow()
{
    delete ui;
    delete m_open_action;
}

