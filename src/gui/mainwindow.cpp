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
    img_listener->undo_last_command();
}

void MainWindow::redo_command(){
    img_listener->redo_last_command();
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
    Image *bilde = toImage(this->imgObject);
    crop_tool& cp = crop_tool::getInstance();
    Image *bilde2 = cp.crop_image(*bilde, c_dialog.get_crop_values());
    this->imgObject = toQImage(bilde2);
    set_image();
    delete bilde;
}



//void MainWindow::crop_image() //@TODO: denne skal endres slik at den kun henter vektor og sender vindere til crop_tool singleton
//{
//    test_vektor = c_dialog.get_crop_values();
//    Image *bilde = toImage(this->imgObject);
//    bilde->crop(Geometry(test_vektor[0],test_vektor[1],
//            test_vektor[2],test_vektor[3]));
//    this->imgObject = toQImage(bilde);
//    set_image();
//    delete bilde;
//}



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


/** Denne er til for å teste ImageMagick egentlig
 * @brief MainWindow::on_pushButton_2_clicked
 */
void MainWindow::on_pushButton_2_clicked()
{

//    crop_dialog c_dialog;

    c_dialog.setModal(true);

    connect(&c_dialog, SIGNAL(signalNewString1(QString)), this, SLOT(crop_image()));



    c_dialog.exec();
}

void MainWindow::changeBrightness(int i) {
    // Endre brightness
    Image *bilde = toImage(this->imgObject);
    bilde->blur();
    this->imgObject = toQImage(bilde);
    set_image();
}

void MainWindow::on_pushButton_clicked()
{
    brightness_dialog b_dialog;
    b_dialog.setModal(true);
    connect(&b_dialog, SIGNAL(signalBrightnessChanged(int)), this, SLOT(changeBrightness(int)));
    b_dialog.exec();
}

Image* MainWindow::toImage(QImage* qimage)
{
    qDebug() << "toImage:" << qimage->width() << qimage->height();

    Image *newImage = new Image(Magick::Geometry(qimage->width(), qimage->height()), Magick::ColorRGB(0.5, 0.2, 0.3));

    double scale = 1 / 256.0;
    newImage->modifyImage();
    Magick::PixelPacket *pixels;
    Magick::ColorRGB mgc;
    for (int y = 0; y < qimage->height(); y++) {
        pixels = newImage->setPixels(0, y, newImage->columns(), 1);
        for (int x = 0; x < qimage->width(); x++) {
            QColor pix = qimage->pixel(x, y);
            //      *pixels++ = Magick::ColorRGB(256 * pix.red(), 256 * pix.green(), 256 * pix.blue());
            mgc.red(scale *pix.red());
            mgc.green(scale *pix.green());
            mgc.blue(scale *pix.blue());
            //      *pixels++ = Magick::ColorRGB(scale *pix.red(), scale * pix.green(), scale * pix.blue());
            *pixels++ = mgc;
        }
        newImage->syncPixels();
    }

    return newImage;
}


QImage* MainWindow::toQImage(Image *image)
{
    qDebug() << "toQImage:" << image->columns() << image->rows();

    QImage *newQImage = new QImage(image->columns(), image->rows(), QImage::Format_RGB32);
    const Magick::PixelPacket *pixels;
    Magick::ColorRGB rgb;
    for (int y = 0; y < newQImage->height(); y++) {
        pixels = image->getConstPixels(0, y, newQImage->width(), 1);
        for (int x = 0; x < newQImage->width(); x++) {
            rgb = (*(pixels + x));
            newQImage->setPixel(x, y, QColor((int) (255 * rgb.red())
                                             , (int) (255 * rgb.green())
                                             , (int) (255 * rgb.blue())).rgb());
        }
    }
    return newQImage;
}
