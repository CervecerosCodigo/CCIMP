#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
//For bildevisning
#include <QImage>
#include <QGraphicsView>
//For TreeView
#include <QTreeView>
#include <QModelIndex>
#include <QDir>
#include <QDirModel>
//For FileSystem model
#include <QFileSystemModel>

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
    void set_image(const QString &path);
    QString imgPath;
    QImage *imgObject;
    QPixmap image;
    QGraphicsScene *scene;
    QGraphicsView *view;


    /*
     * TreeView med FileSystem model
     */
    QString fs_path;
    QFileSystemModel *fs_model;
    QStringList fs_filter;
    QModelIndex fs_index;
    void set_fs_view();

public slots:
    void open();
    void showDebugMsg();
private slots:
    void on_treeView_clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
