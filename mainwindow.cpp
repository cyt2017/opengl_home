#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->parent = this;
    this->installEventFilter(ui->widget);

    ui->widget->init();
    ui->widget->setMouseTracking(true);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    timer->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout()
{
    QString srtr =ui->widget->mousePos;
     ui->widget->drawImage();
     ui->label_mouse->setText(srtr);
//     printf("onTimeout %s\n",srtr.toLatin1().data());
     fflush(stdout);

}
