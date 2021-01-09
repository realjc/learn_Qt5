#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void init();
    void updateParentItem(QTreeWidgetItem* item);


private:
    Ui::Widget *ui;

public slots:
    void treeItemChanged(QTreeWidgetItem* item);
};
#endif // WIDGET_H
