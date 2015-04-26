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
#include <vector>
#include "brightness_dialog.h"
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

    crop_dialog c_dialog;
    brightness_dialog b_dialog;
    vector<int> test_vektor;
    Magick::Image *edit_image;
    /*
     * Denne blir brukt til verktøy som feks brightness der vi i
     * utgangspunkt trenger å ta vare på original bilde slik
     * det såg ut før vi begynte å editere det.
     */
    Magick::Image *edit_orig_image;

public:
    void set_event_listener(event_listener* l);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_crop_tool(image_tool* t);
    void set_updated_image(QImage* updated_image);
    void callback_image_edited(QImage* img) override;

private:
    Ui::MainWindow *ui;

    Image* toImage(QImage* qimage);
    QImage* toQImage(Image* image);
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
    void changeBrightness();
    void print_vector();
    void crop_image();
    void execute_tool_on_image();

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
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

};

#endif // MAINWINDOW_H
