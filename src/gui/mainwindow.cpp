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
    QString path = QCoreApplication::applicationDirPath()+"/../res/img/bilde1.jpg"; //dette blidet settes da man starter programmet
    set_image(path);
    qDebug() << "Running path " << QCoreApplication::applicationDirPath();

    //Setter opp en tree view
    set_fs_view();
}

void MainWindow::createConnections(){
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(save_as()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionRotateLeft, SIGNAL(triggered()), this, SLOT(rotate_left()));
    connect(ui->actionRotateRight, SIGNAL(triggered()), this, SLOT(rotate_right()));
    connect(ui->actionZoom_In, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(ui->actionZoom_Out, SIGNAL(triggered()), this, SLOT(zoomOut()));
    connect(ui->actionActual_size, SIGNAL(triggered()), this, SLOT(actualSize()));
    connect(ui->actionZoom_to_fit, SIGNAL(triggered()), this, SLOT(zoomToFit()));
}

/** FileOpen dialog
 * @brief MainWindow::open
 */
void MainWindow::open(){
    filePath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)")
                );

    load_file(filePath);
}

/** Lagre som
 * @TODO Her borde vi bruke en eller annen exception.
 * @brief MainWindow::save_as
 */
void MainWindow::save_as(){
    filePath = QFileDialog::getSaveFileName(
                this,
                tr("Save As"),
                "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)")
                );

    QFile outFile(filePath);
    if (outFile.open(QIODevice::WriteOnly)){
        imgObject->save(filePath);
        outFile.close();
    }

}

void MainWindow::save(){
    QFile outFile(original_filePath);
    if (outFile.open(QIODevice::WriteOnly)){
        imgObject->save(original_filePath);
        outFile.close();
        QString info = "File saved in\n" + original_filePath;
        QMessageBox::information(this, "Save", info);
    }
}

/** Laster inn filen
 * @brief MainWindow::load_file
 * @param fileName
 */
void MainWindow::load_file(const QString &fileName){
    set_image(fileName);
}

/** Setter bilde i vindu
 * @brief MainWindow::set_image
 * @param path
 */
void MainWindow::set_image(const QString &path)
{
    qDebug() << "set_image: " << path;
    original_filePath = path;
    imgObject = new QImage();
    imgObject->load(path);

    //Viser statistikk
    show_stats(imgObject);

    image = QPixmap::fromImage(*imgObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
    if(img_listener_set)
        img_listener->on_image_change(*imgObject);   //notify controller by sending reference of the new image
}


void MainWindow::set_image()
{
    //Viser statistikk
    show_stats(imgObject);

    image = QPixmap::fromImage(*imgObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);

}




/** Setter opp file system view
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
    ui->treeView->setColumnWidth(0, 400); //Bruker denne foreløpig ettersom automatisk resizing på raden over vil ikke fungere.
}

void MainWindow::show_stats(QImage *img){
    image_statistics stat;
    ui->textEdit->setText(stat.get_img_stat(*img));
}


void MainWindow::rotate_left() {
    qDebug()<< "Rotate left ran";
    QTransform rot;
    rot.rotate(-90);
    QImage nyttBilde = this->imgObject->transformed(rot);
    this->imgObject = (QImage*)&nyttBilde;
    set_image();
}


void MainWindow::rotate_right() {
    qDebug()<< "Rotate right ran";
    QTransform rot;
    rot.rotate(90);
    QImage nyttBilde = this->imgObject->transformed(rot);
    this->imgObject = (QImage*)&nyttBilde;
    set_image();
}


void MainWindow::zoomIn() {
    qDebug()<< "zoomIn() ran";

}


void MainWindow::zoomOut() {
    qDebug()<< "zoomOut() ran";

}

void MainWindow::actualSize() {
    qDebug()<< "actualSize() ran";

}

void MainWindow::zoomToFit() {
    qDebug()<< "zoomToFit() ran";
    this->view->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
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

/** Skriver ut i terminal path til den mappe eller fil som man klikket på i
 * filesystemview.
 * @brief MainWindow::on_treeView_clicked
 * @param index
 */
void MainWindow::on_treeView_clicked()
{
    QString new_img = fs_model->filePath(ui->treeView->currentIndex());
//    qDebug() << new_img;
//    set_image(new_img);
}


/*
 * ************************************************************************
 * Slutt på ting som brukes til debugging
 *
 * ************************************************************************
 */


void MainWindow::on_treeView_pressed()
{
    QString new_img = fs_model->filePath(ui->treeView->currentIndex());
    //qDebug() << new_img;
    set_image(new_img);
}

void MainWindow::set_image_listener(listen_for_image_change *l){
    img_listener_set = true;
    img_listener = l;

}

