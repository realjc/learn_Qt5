#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_add1_textChanged();
    void on_add2_textChanged();
    void on_Add_clicked();
private:
    int a,b,res;
};
#endif // MAINWINDOW_H
