#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QGraphicsView>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void createConnections();
    void loadFile(const QString &fileName);


    QString filePath;


    //Midlertidlig for å sette bilde fra main vindu
    void setImage(const QString &path);
    QString imgPath;
    QImage *imgObject;
    QPixmap image;
    QGraphicsScene *scene;
    QGraphicsView *view;

public slots:
    void open();
    void showDebugMsg();
};

#endif // MAINWINDOW_H
