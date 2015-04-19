#include "gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QWidget::showMaximized();

    //setCentralWidget(ui->graphicsView); //den respekterer ikke andre windgets

    createConnections();

    //Setter bilde ved boot
    QString path = "../res/img/bilde1.jpg"; //dette blidet settes da man starter programmet
    set_image(path);

    //Setter opp en tree view
    set_fs_view();
}

void MainWindow::createConnections(){
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
}

/**
 * FileOpen dialog
 * @brief MainWindow::open
 */
void MainWindow::open(){
    filePath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)")
                );
    loadFile(filePath);
}

/**
 * Laster inn filen
 * @brief MainWindow::loadFile
 * @param fileName
 */
void MainWindow::loadFile(const QString &fileName){
    set_image(fileName);
}

/**
 * Setter bilde i vindu
 * @brief MainWindow::setImage
 * @param path
 */
void MainWindow::set_image(const QString &path)
{
    imgObject = new QImage();
    imgObject->load(path);
    image = QPixmap::fromImage(*imgObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
}

/**
 * Setter opp file system view
 * @brief MainWindow::set_fs_view
 */
void MainWindow::set_fs_view()
{
    fs_path = QDir::homePath();
    fs_model = new QFileSystemModel();
    fs_index = fs_model->index(fs_path,0);
    fs_model->setReadOnly(true);
    fs_model->setRootPath(fs_path);

    fs_filter << "*.png" << "*.jpg";
    fs_model->setNameFilters(fs_filter);
    fs_model->setNameFilterDisables(false);
    ui->treeView->setSortingEnabled(true);
    ui->treeView->setModel(fs_model);
    ui->treeView->expand(fs_index);
    ui->treeView->scrollTo(fs_index);
    ui->treeView->setCurrentIndex(fs_index);
//    ui->treeView->resizeColumnToContents(0);
    ui->treeView->setColumnWidth(0, 200); //Bruker denne foreløpig ettersom automatisk resizing på raden over vil ikke fungere.
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * ************************************************************************
 * Her kommer kule ting til debuggin som skal slettes etter at vi er ferdig
 *
 * ************************************************************************
 */

void MainWindow::showDebugMsg(){
    qDebug() << "Debug melding fra main window";

}

/**
 * Skriver ut i terminal path til den mappe eller fil som man klikket på i
 * filesystemview.
 * @brief MainWindow::on_treeView_clicked
 * @param index
 */
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    qDebug() << ui->treeView->currentIndex();
    qDebug() << fs_model->filePath(ui->treeView->currentIndex());
}
