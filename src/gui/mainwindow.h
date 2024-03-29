#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <vector>
#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <QDirIterator>
#include <Magick++.h>
#include "controller/image_statistics.h"
#include "controller/event_listener.h"
#include "controller/callback_iface.h"
#include "controller/ccimp_vector.h"
//#include "controller/callback_error_iface.h"
#include "gui/about_dialog.h"
#include "gui/crop_dialog.h"
#include "gui/blur_dialog.h"
#include "gui/contrast_dialog.h"
#include "gui/rotate_dialog.h"
#include "gui/color_balance_dialog.h"
#include "gui/encipher_dialaog.h"
#include "gui/sharpness_dialog.h"
#include "gui/brightness_dialog.h"
#include "gui/auto_gamma_dialog.h"
#include "gui/auto_level_dialog.h"
#include "gui/scale_dialog.h"

#include "img_tools/image_tool.h"
#include "img_tools/tool_auto_gamma.h"
#include "img_tools/tool_auto_level.h"
#include "img_tools/tool_scale.h"


//using namespace Magick; //TODO@: Husk å slette denne å fikse før innlevering

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public callback_iface
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
    sharpness_dialog sharpnessDialog;
    auto_gamma_dialog autoGammaDialog;
    auto_level_dialog autoLevelDialog;
    scale_dialog scaleDialog;


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
    void set_auto_gamma_tool(image_tool* t);
    void set_auto_level_tool(image_tool* t);
    void set_sharpen_tool(image_tool* t);
    void set_scale_tool(image_tool* t);

    bool user_want_to_save();
    void update_gui_resize();
    void update_gui();
    void set_updated_image(QImage* updated_image);
    void set_image();
    void callback_image_edited(QImage* img) override;
    void callback_report_image_is_original() override;
    void exception_in_image_processing(QString err_title, QString err_msg);
    callback_iface* get_callback_listener() override;

private:
    Ui::MainWindow *ui;
    QString filePath;
    QString original_filePath;
    QString imgPath;
    QImage *imgObject;
    QImage *imgBackground;
    QPixmap image;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QString fs_path;
    QFileSystemModel *fs_model;
    QStringList fs_filter;
    QModelIndex fs_index;
    double zoomVerdi, zoomFloorValue, zoomRoofValue;

    void createConnections();
    void load_file(const QString &fileName);


    //Setter opp bildevisning
    void set_image(const QString &path);
    void resizeEvent ( QResizeEvent* e );


    //TreeView med FileSystem model
    void set_fs_view();


    /*
     * Dette er til for å frem og tilbake knapper skal fungere
     */
    int pic_count_in_dir=0;
    int pic_i;
    QString selected_file;
    QDir dir_of_selected_file;
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
    void on_treeView_pressed();
    void rotate_left();
    void rotate_right();
    void zoomIn();
    void zoomOut();
    void zoomToFit();
    void undo_command();
    void redo_command();
    void on_blurButton_clicked();
    void on_brightnessButton_clicked();
    void on_cropButton_clicked();
    void on_contrastButton_clicked();
    void on_rotateButton_clicked();
    void on_colorBalanceButton_clicked();
    void on_actionAbout_CCIMP_triggered();
    void on_encipherButton_clicked();
    void on_actionNext_triggered();
    void on_actionPrevoius_triggered();
    void closeEvent(QCloseEvent *);

    void on_actionActual_size_triggered();
    void on_actionReload_triggered();
    void on_sharpnessButton_clicked();
    void on_autoGammaButton_clicked();
    void on_autoLevelButton_clicked();
    void on_scaleButton_clicked();
};

#endif // MAINWINDOW_H
