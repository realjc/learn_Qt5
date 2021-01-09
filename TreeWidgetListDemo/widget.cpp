#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(treeItemChanged(QTreeWidgetItem*)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0,"水果");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem11 = new QTreeWidgetItem(group1);
    subItem11->setText(0,"苹果");
    subItem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem11->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem12 = new QTreeWidgetItem(group1);
    subItem12->setText(0,"香蕉");
    subItem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem12->setCheckState(0,Qt::Unchecked);

}

void Widget::treeItemChanged(QTreeWidgetItem* item)
{

    if (Qt::Checked == item->checkState(0)||Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        if(item->checkState(0)==Qt::Checked)
        {
            for (int i = 0; i < count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Checked);
            }
        }
        else if(item->checkState(0)==Qt::Unchecked)
        {
            for (int i = 0; i < count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Unchecked);
            }
        }
        if(count==0) updateParentItem(item);
    }
    return;
}


void Widget::updateParentItem(QTreeWidgetItem* item){
    QTreeWidgetItem* parent = item->parent();
    if(parent == nullptr) return;
    int selectedCount = 0;
    int childCount = parent->childCount();
    for(int i=0;i<childCount;i++){
        QTreeWidgetItem *childItem = parent->child(i);
        if(childItem->checkState(0)==Qt::Checked) selectedCount++;
    }
    if(selectedCount==0) parent->setCheckState(0,Qt::Unchecked);
    else if(selectedCount>0 && selectedCount<childCount){
        parent->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectedCount==childCount){
        parent->setCheckState(0,Qt::Checked);
    }
    return;
}
