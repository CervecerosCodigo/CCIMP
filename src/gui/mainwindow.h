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
#include <Magick++.h>
#include <iostream>
#include "controller/image_statistics.h"
#include "controller/event_listener.h"
#include "controller/callback_iface.h"
#include "controller/ccimp_vector.h"
#include "gui/crop_dialog.h"
#include "gui/blur_dialog.h"
#include "gui/contrast_dialog.h"
#include "gui/rotate_dialog.h"
#include "gui/color_balance_dialog.h"
#include <vector>
#include "gui/brightness_dialog.h"
#include "img_tools/img_obj_converter.h"
#include <QSignalMapper>
#include "img_tools/image_tool.h"


using namespace Magick; //TODO@: Husk å slette denne å fikse før innlevering

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public callback_iface
{
    Q_OBJECT

    //Setter opp dialogvinduer
    crop_dialog cropDialog;
    brightness_dialog brightnessDialog;
    contrast_dialog contrastDialog;
    blur_dialog blurDialog;
    rotate_dialog rotateDialog;
    color_balance_dialog colorBalanceDialog;

public:
    void set_event_listener(event_listener* l);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_crop_tool(image_tool* t);

    void set_blur_tool(image_tool* t);

    void set_brightness_tool(image_tool* t);
    void set_contrast_tool(image_tool* t);
    void set_rotate_tool(image_tool* t);
    void set_color_balance_tool(image_tool* t);

    void set_rotate_tool(image_tool* t);
    void update_gui_resize();
    void set_updated_image(QImage* updated_image);
    void callback_image_edited(QImage* img) override;

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
    void set_boot_image(); //seter startbilde fra resource filen
    void resizeEvent ( QResizeEvent* e );

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
    bool event_listener_set = false;  //må settes for at img_listener kan brukes
    event_listener* event_listen;

public slots:
    void open();
    void save();
    void save_as();
    void showDebugMsg();
    void execute_tool_on_image();

private slots:
    //void on_treeView_clicked();
    void on_treeView_pressed();
    void rotate_left();
    void rotate_right();
    void zoomIn();
    void zoomOut();
    void actualSize();
    void zoomToFit();
    void undo_command();
    void redo_command();
    void on_blurButton_clicked();
    void on_brightnessButton_clicked();
    void on_cropButton_clicked();
    void on_contrastButton_clicked();
    void on_rotateButton_clicked();
//    void window_resize_done();
    void on_colorBalanceButton_clicked();
};

#endif // MAINWINDOW_H
