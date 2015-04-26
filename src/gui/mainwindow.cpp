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

    //Opretter imgae objekt som skal brukes til redigering.
//    edit_image = new Magick::Image;

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
    qDebug() << "set_image: " << path;
    original_filePath = path;
    imgObject = new QImage();
    imgObject->load(path);
    if(event_listener_set)
        event_listen->on_new_image(*imgObject);   //notify controller by sending reference of the new image
    set_updated_image(imgObject);
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
//    qDebug()<< "Rotate left ran";
//    QTransform rot;
//    rot.rotate(-90);
//    QImage nyttBilde = this->imgObject->transformed(rot);
//    this->imgObject = (QImage*)&nyttBilde;
//    set_image();
}


void MainWindow::rotate_right() {
//    qDebug()<< "Rotate right ran";
//    QTransform rot;
//    rot.rotate(90);
//    QImage nyttBilde = this->imgObject->transformed(rot);
//    this->imgObject = (QImage*)&nyttBilde;
//    set_image();
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

/** Denne metoden var til bruk for å teste dersom det er enkelt nok til
 * å ta imot data fra et dialogvindu og skrive ut det i main window.
 * @brief MainWindow::print_vector
 */
void MainWindow::print_vector()
{

//    test_vektor = c_dialog.get_crop_values();
    std::vector<int>::iterator vi = test_vektor.begin();
    while(vi != test_vektor.end()){
        std::cout << "Cropping: " << *vi;
        vi++;
    }
}

/** Denne skal beskjære bilde.
 * Funksjonen skal seinere flyttes til controller.
 * @brief MainWindow::crop_image
 */
void MainWindow::crop_image() //@TODO: denne skal endres slik at den kun henter vektor og sender vindere til crop_tool singleton
{
//    Image *bilde = toImage(this->imgObject);
//    Image *bilde = img_obj_converter::to_Image(this->imgObject);
//    crop_tool& cp = crop_tool::getInstance();
//    Image *bilde2 = cp.crop_image(*bilde, c_dialog.get_crop_values());
////    this->imgObject = toQImage(bilde2);
//    set_updated_image(img_obj_converter::to_QImage(bilde2));
//    delete bilde, bilde2;
}

void MainWindow::changeBrightness() {
    // Endre brightness

    edit_image = new Image(*edit_orig_image);
    edit_image->brightnessContrast((brightnessDialog.get_slider_value())*1.0,0.0);
    this->imgObject = img_obj_converter::to_QImage(*edit_image);
    set_updated_image(img_obj_converter::to_QImage(*edit_image));
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

void MainWindow::set_event_listener(event_listener *l){
    event_listener_set = true;
    event_listen = l;

}



//set-metode for crop-tool
void MainWindow::set_crop_tool(image_tool *t){
    cropDialog.set_tool(t);
}

void MainWindow::set_brightness_tool(image_tool *t)
{
    brightnessDialog.set_tool(t);
}

void MainWindow::callback_image_edited(QImage* img){
    set_updated_image(img);
}


/**
 * Felles SLOT som utføres uansett hvilket verktøy som er brukt.
 */
void MainWindow::execute_tool_on_image(){
    qDebug() << "Executing tool" ;
    event_listen->execute_tool_on_image(this);
}


void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "on_pushButton_3_clicked() kjørt";
    event_listen->on_clicked_tool(blur_dia.get_tool());
    blur_dia.setModal(true);

    connect(&blur_dia, SIGNAL(signalBlurChanged()), this, SLOT(execute_tool_on_image()));

    blur_dia.exec();
}

void MainWindow::set_blur_tool(image_tool *t) {
    qDebug() << "set_blur_tool kjørt";
    blur_dia.set_tool(t);
}

void MainWindow::on_brightnessButton_clicked()
{
    event_listen->on_clicked_tool(brightnessDialog.get_tool());
//    edit_orig_image = img_obj_converter::to_Image(*imgObject);
    brightnessDialog.setModal(true);
    connect(&brightnessDialog, SIGNAL(signalBrightnessChanged()), this, SLOT(execute_tool_on_image()));
    brightnessDialog.exec();
}

void MainWindow::on_cropButton_clicked()
{
    event_listen->on_clicked_tool(cropDialog.get_tool());
    cropDialog.setModal(true);
    connect(&cropDialog, SIGNAL(signalNewString1(QString)), this, SLOT(execute_tool_on_image()));
    cropDialog.exec();

}
