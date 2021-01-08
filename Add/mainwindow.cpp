#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add1_textChanged()
{
    QString s1 = ui->add1->toPlainText();
    this->a = s1.toInt();
}

void MainWindow::on_add2_textChanged()
{
    QString s2 = ui->add2->toPlainText();
    this->b = s2.toInt();
}

void MainWindow::on_Add_clicked(){
    res = a+b;
    ui->res->setPlainText(QString::number(res));
}
