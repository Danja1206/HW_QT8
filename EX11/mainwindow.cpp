#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::fileManager = new FileManager(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::name()
{
    return ui->lineEdit->text();
}
