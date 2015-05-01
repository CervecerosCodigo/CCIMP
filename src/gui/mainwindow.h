#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
//For bildevisning
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
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
#include "gui/about_dialog.h"
#include "gui/crop_dialog.h"
#include "gui/blur_dialog.h"
#include "gui/contrast_dialog.h"
#include "gui/rotate_dialog.h"
#include "gui/color_balance_dialog.h"
#include "gui/encipher_dialaog.h"
#include <vector>
#include "gui/brightness_dialog.h"
#include "img_tools/img_obj_converter.h"
#include <QSignalMapper>
#include "img_tools/image_tool.h"
#include "controller/callback_error_iface.h"


using namespace Magick; //TODO@: Husk å slette denne å fikse før innlevering

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public callback_iface, public callback_error_iface
{
    Q_OBJECT

    //Setter opp dialogvinduer
    about_dialog aboutDialog;
    crop_dialog cropDialog;
    brightness_dialog brightnessDialog;
    contrast_dialog contrastDialog;
    blur_dialog blurDialog;
    rotate_dialog rotateDialog;
    color_balance_dialog colorBalanceDialog;
    encipher_dialaog encipherDialog;

public:
    void set_event_listener(event_listener* l);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //set-metoder for tools
    void set_crop_tool(image_tool* t);
    void set_blur_tool(image_tool* t);
    void set_brightness_tool(image_tool* t);
    void set_contrast_tool(image_tool* t);
    void set_rotate_tool(image_tool* t);
    void set_color_balance_tool(image_tool* t);
    void set_secure_tool(image_tool* t);

    bool user_want_to_save();
    void update_gui_resize();
    void set_updated_image(QImage* updated_image);
    void callback_image_edited(QImage* img) override;
    void callback_report_image_is_original() override;
    void exception_in_image_processing(QString err_title, QString err_msg) override;
    callback_iface* get_callback_listener() override;
private:
    Ui::MainWindow *ui;

    void createConnections();
    void load_file(const QString &fileName);
    void wheelEvent(QWheelEvent* event);

    QString filePath;
    QString original_filePath;

    double zoomVerdi;


    /*
     * Setter opp bildevisning
     */
    void set_graphics_environment();
    void set_image(const QString &path);
    void resizeEvent ( QResizeEvent* e );

    QString imgPath;
    QImage *imgObject;
    QImage *imgBackground;
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
     * Dette er til for å frem og tilbake knapper skal fungere
     */
    int pic_count_in_dir=0;
    int pic_i;
    std::vector<QString> pics_in_folder;

    /*
     * For å vise bildestatistikk
     */
    void show_stats(QImage*);
    /**
     * Forskjellige lyttere mellom gui og controllere
     */
    bool event_listener_set = false;  //må settes for at img_listener kan brukes
    event_listener* event_listen;

    //Forskjellige booleans som brukes for å sjekke status og beskytte knapper
    bool image_is_loaded = false;
    bool image_edited_not_saved = false;


public slots:
    void open();
    void save();
    void save_as();

    void execute_value_changed();
    void execute_acceptbtn_pressed();
    void execute_cancelbtn_pressed();
    void execute_change_and_accept();

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
    void on_actionAbout_CCIMP_triggered();
    void on_encipherButton_clicked();
    void on_actionNext_triggered();
    void on_actionPrevoius_triggered();
    void closeEvent(QCloseEvent *);

};

#endif // MAINWINDOW_H
