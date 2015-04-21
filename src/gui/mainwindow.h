#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
//For bildevisning
#include <QImage>
#include <QGraphicsView>
//For FileSystem model
#include <QFileSystemModel>
#include <QModelIndex>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <iostream>

#include "model/image_statistics.h"


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
    void load_file(const QString &fileName);


    QString filePath;
    QString original_filePath;


    /*
     * Setter opp bildevisning
     */
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

    /*
     * For å vise bildestatistikk
     */
    void show_stats(QImage*);

public slots:
    void open();
    void save();
    void save_as();
    void showDebugMsg();
private slots:
    void on_treeView_clicked();
    void on_treeView_pressed();

};

#endif // MAINWINDOW_H
