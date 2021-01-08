#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *menuFile = new QMenu("&File");
    QAction *actionOpen;
    actionOpen = new QAction("&Open", this);
    actionOpen->setShortcut(QKeySequence::Open);
    menuFile->addAction(actionOpen);
//    menuBar()->addMenu(menuFile);
//    QToolBar *toolBarFile = addToolBar("File");
//    toolBarFile->addAction(actionOpen);
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    this->procImage = this->oriImage;
    QImage imgScaled=this->procImage.scaled(ui->frame2->size(),Qt::KeepAspectRatio);
    ui->frame2->setPixmap(QPixmap::fromImage(imgScaled));
    ui->frame2->resize(ui->frame2->pixmap()->size());
    return;
}

void MainWindow::open()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Open");
    if (!dir.isEmpty()) {
        cv::Mat img = cv::imread(dir);
        cv::Mat rgb;
        cv::cvtColor(img,rgb,cv::COLOR_BGR2RGB);
        this->oriImage =QImage((const unsigned char*)(rgb.data),
                    rgb.cols,rgb.rows,
                    rgb.cols*rgb.channels(),
                    QImage::Format_RGB888);
    }

    QImage imgScaled=this->oriImage.scaled(ui->frame1->size(),Qt::KeepAspectRatio);
    ui->frame1->setPixmap(QPixmap::fromImage(imgScaled));
    ui->frame1->resize(ui->frame1->pixmap()->size());
    return;
}
