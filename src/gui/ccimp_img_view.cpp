#include "ccimp_img_view.h"
#include "ui_ccimp_img_view.h"

ccimp_img_view::ccimp_img_view(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::ccimp_img_view)
{
    ui->setupUi(this);

//    imgPath = "../res/img/bilde1.jpg";

//    imgObject = new QImage();
//    imgObject->load(imgPath);
//    image = QPixmap::fromImage(*imgObject);


//    scene = new QGraphicsScene(this);
//    scene->addPixmap(image);
//    scene->setSceneRect(image.rect());
//    ui->graphicsView->setScene(scene);

}

void ccimp_img_view::set_current_gui_image(const QString &path){

    imgObject = new QImage();
    imgObject->load(path);
    image = QPixmap::fromImage(*imgObject);


    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
}

void ccimp_img_view::openImage()
{
    qDebug() << "QDebug: ccimp_img_view: opening an image";
}

ccimp_img_view::~ccimp_img_view()
{
    delete ui;
}
