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

    createConnections();
    QString path = "../res/img/bilde1.jpg"; //dette blidet settes da man starter programmet
    ui->graphicsView->set_current_gui_image(path);
}

void MainWindow::createConnections(){
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
    loadFile(filePath);
}

void MainWindow::loadFile(const QString &fileName){
    ui->graphicsView->set_current_gui_image(fileName);
}

void MainWindow::showDebugMsg(){
    qDebug() << "Debug melding fra main window";

}

MainWindow::~MainWindow()
{
    delete ui;
}
