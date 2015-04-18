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

    //Setter bilde ved boot
    QString path = "../res/img/bilde1.jpg"; //dette blidet settes da man starter programmet
    setImage(path);

    //Initiliserer tree view
    model = new QDirModel(this);
    model->setReadOnly(true);
    model->setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->treeView->setModel(model);
    file_view_on_init();

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
    setImage(fileName);
}

void MainWindow::setImage(const QString &path)
{
    imgObject = new QImage();
    imgObject->load(path);
    image = QPixmap::fromImage(*imgObject);


    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
}

void MainWindow::file_view_on_init()
{
    path = QDir::homePath();
    index = model->index(QDir::homePath());
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);
}

void MainWindow::showDebugMsg(){
    qDebug() << "Debug melding fra main window";

}

MainWindow::~MainWindow()
{
    delete ui;
}


//Midlertidlig for å huske hvrdan man henter ut indeksen da man klikker i treeview
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    qDebug() << ui->treeView->currentIndex();
    qDebug() << model->filePath(ui->treeView->currentIndex());
}
