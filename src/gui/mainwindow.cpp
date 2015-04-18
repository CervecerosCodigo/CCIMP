#include "gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized();

    //setCentralWidget(ui->graphicsView); //den respekterer ikke andre windgets


    //Signals & Sluts
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));


}


void MainWindow::open(){
    filePath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)")
                );
}

void MainWindow::showDebugMsg(){
    qDebug() << "Debug melding fra main window";

}

MainWindow::~MainWindow()
{
    delete ui;
}
