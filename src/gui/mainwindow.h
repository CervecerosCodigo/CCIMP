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
#include "model/listen_for_image_change.h"
#include "slider_dialog.h"
#include "model/ccimp_vector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void set_image_listener(listen_for_image_change* l);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void createConnections();
    void load_file(const QString &fileName);

    QString filePath;
    QString original_filePath;

    slider_dialog *brightnessDialog;


    /*
     * Setter opp bildevisning
     */
    void set_image(const QString &path);
    void set_image();
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
    /**
     * Forskjellige lyttere mellom gui og controllere
     */
    bool img_listener_set = false;  //må settes for at img_listener kan brukes
    listen_for_image_change* img_listener;

public slots:
    void open();
    void save();
    void save_as();
    void showDebugMsg();
private slots:
    void on_treeView_clicked();
    void on_treeView_pressed();
    void rotate_left();
    void rotate_right();
    void zoomIn();
    void zoomOut();
    void actualSize();
    void zoomToFit();
    void undo_command();
    void redo_command();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
