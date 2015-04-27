#include "gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QWidget::showMaximized();

    createConnections();

    //Setter bilde ved boot
    QString path = QCoreApplication::applicationDirPath()+"/../res/img/bilde1.jpg"; //dette blidet settes da man starter programmet
    set_image(path);
    qDebug() << "Running path " << QCoreApplication::applicationDirPath();

    //Setter opp en tree view
    set_fs_view();

    //Setter opp boot image
    set_boot_image();

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
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(undo_command()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(redo_command()));


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

void MainWindow::set_boot_image()
{
    QImage *boot_image = new QImage();
    boot_image->load(":/img/img/CCIMP_background.png");
//    boot_image->load("../res/img/bilde1.jpg");
    QPixmap boot_pixmap = QPixmap::fromImage(*boot_image);
    QGraphicsScene *boot_scene = new QGraphicsScene(this);
    boot_scene->addPixmap(boot_pixmap);
    boot_scene->setSceneRect(boot_pixmap.rect());
    ui->graphicsView->setScene(boot_scene);
}

/** Laster inn filen
 * @brief MainWindow::load_file
 * @param fileName
 */
void MainWindow::load_file(const QString &fileName){
    set_image(fileName);
}



/** Setter bilde i vindu når åpnes fra TreeView eller Open
 * @brief MainWindow::set_image
 * @param path
 */
void MainWindow::set_image(const QString &path)
{

    if(!path.isNull() || !path.isEmpty()){

        original_filePath = path;
        imgObject = new QImage();
        imgObject->load(path);
        new_image_loaded = true;
        notify_event_image_changed();
        set_updated_image(imgObject);

    }else{
        qDebug() << "Filstien er tom eller null!";
    }
}




/** Etter et bilde er åpnet, så brukes denne metoden for å updatere og vise i GUI
 * @brief MainWindow::set_updated_image
 * @param updated_image
 */
void MainWindow::set_updated_image(QImage* updated_image)
{
    imgObject = updated_image;

    //Viser statistikk
    show_stats(imgObject);

    image = QPixmap::fromImage(*imgObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
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
    notify_event_image_changed();
    event_listen->on_clicked_tool(rotateDialog.get_tool());
    rotateDialog.rotate_left();
    connect(&rotateDialog, SIGNAL(signalRotationChanged()), this, SLOT(execute_tool_on_image()));
}


void MainWindow::rotate_right() {
    notify_event_image_changed();
    event_listen->on_clicked_tool(rotateDialog.get_tool());
    rotateDialog.rotate_right();
    connect(&rotateDialog, SIGNAL(signalRotationChanged()), this, SLOT(execute_tool_on_image()));
}


void MainWindow::zoomIn() {
    qDebug()<< "zoomIn() ran";
    //scene->
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


void MainWindow::undo_command(){
    event_listen->undo_last_command();
}

void MainWindow::redo_command(){
    event_listen->redo_last_command();
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
    const QString new_img = fs_model->filePath(ui->treeView->currentIndex());
    set_image(new_img);
}


/**
 * @brief MainWindow::set_event_listener
 * @param l
 * Setter eventlytteren som skal sende events til controller
 */
void MainWindow::set_event_listener(event_listener *l){
    event_listener_set = true;
    event_listen = l;

}

/**
 * @brief MainWindow::notify_event_image_changed
 * Privat metode som må kalles hver gang et man skal inn på en tool, eller når nytt bilde lastes.
 */
void MainWindow::notify_event_image_changed(){
    if(event_listener_set){
        if(new_image_loaded){
            event_listen->on_new_image(*imgObject);   //notify controller by sending reference of the new image
            new_image_loaded = false;
        }
    }
}

//set-metode for crop-tool
void MainWindow::set_crop_tool(image_tool *t){
    cropDialog.set_tool(t);
}


void MainWindow::set_brightness_tool(image_tool *t)
{
    brightnessDialog.set_tool(t);
}

void MainWindow::set_contrast_tool(image_tool *t)
{
    contrastDialog.set_tool(t);
}

void MainWindow::set_rotate_tool(image_tool *t)
{
    rotateDialog.set_tool(t);
}

void MainWindow::set_blur_tool(image_tool *t) {
    blurDialog.set_tool(t);
}



/**Er en event-implementasjon som kalles fra image_wrapper
 * etter at et bilde er behandlet, og skal vises i gui igjen.
 * @brief MainWindow::callback_image_edited
 * @param img
 */
void MainWindow::callback_image_edited(QImage* img){
    set_updated_image(img);
}


/**
 * Felles SLOT som utføres uansett hvilket verktøy som er brukt.
 */
void MainWindow::execute_tool_on_image(){
    event_listen->execute_tool_on_image(this);
}


void MainWindow::on_blurButton_clicked()
{
    notify_event_image_changed();
    event_listen->on_clicked_tool(blurDialog.get_tool());
    connect(&blurDialog, SIGNAL(signalBlurChanged()), this, SLOT(execute_tool_on_image()));
    blurDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
    blurDialog.exec();
}

void MainWindow::on_brightnessButton_clicked()
{
    notify_event_image_changed();
    event_listen->on_clicked_tool(brightnessDialog.get_tool());
    connect(&brightnessDialog, SIGNAL(signalBrightnessChanged()), this, SLOT(execute_tool_on_image()));
    brightnessDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
    brightnessDialog.exec();
}

void MainWindow::on_cropButton_clicked()
{
    notify_event_image_changed();
    event_listen->on_clicked_tool(cropDialog.get_tool());
    connect(&cropDialog, SIGNAL(signalNewString1(QString)), this, SLOT(execute_tool_on_image()));
    cropDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
    cropDialog.exec();

}

void MainWindow::on_contrastButton_clicked()
{
    notify_event_image_changed();
    event_listen->on_clicked_tool(contrastDialog.get_tool());
    connect(&contrastDialog, SIGNAL(signalContrastChanged()), this, SLOT(execute_tool_on_image()));
    contrastDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
    contrastDialog.exec();
}

void MainWindow::on_rotateButton_clicked()
{
    notify_event_image_changed();
    event_listen->on_clicked_tool(rotateDialog.get_tool());
    connect(&rotateDialog, SIGNAL(signalRotationChanged()), this, SLOT(execute_tool_on_image()));
    rotateDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
    rotateDialog.exec();
}
