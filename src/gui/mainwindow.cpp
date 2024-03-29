#include "gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createConnections();

    //Setter opp en tree view
    set_fs_view();




    //Zoom verdier
    zoomVerdi = 1;
    zoomFloorValue = 0.5;
    zoomRoofValue = 5.0;

}

void MainWindow::createConnections(){
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(save_as()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionRotateLeft, SIGNAL(triggered()), this, SLOT(rotate_left()));
    connect(ui->actionRotateRight, SIGNAL(triggered()), this, SLOT(rotate_right()));
    connect(ui->actionZoom_In, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(ui->actionZoom_Out, SIGNAL(triggered()), this, SLOT(zoomOut()));
    connect(ui->actionZoom_to_fit, SIGNAL(triggered()), this, SLOT(zoomToFit()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(undo_command()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(redo_command()));

}

/**FileOpen dialog
 * @brief MainWindow::open
 */
void MainWindow::open(){
    if(!user_want_to_save()){
        filePath = QFileDialog::getOpenFileName(
                    this,
                    tr("Open File"),
                    "",
                    tr("JPEG (*.jpg *.jpeg);;PNG (*.png)")
                    );

        load_file(filePath);
    }
}


/**Catcher endringer i vindustørrelse og kjører update-metode
 * @brief MainWindow::resizeEvent
 * @param e
 */
void MainWindow::resizeEvent(QResizeEvent *e){
    update_gui_resize();
}


/**Lagre som
 * @TODO Her borde vi bruke en eller annen exception.
 * @brief MainWindow::save_as
 */
void MainWindow::save_as(){
    if(image_is_loaded){
        filePath = QFileDialog::getSaveFileName(
                    this,
                    tr("Save As"),
                    "",
                    tr("JPEG (*.jpg *.jpeg);;PNG (*.png)")
                    );

        QFile outFile(filePath);
        if (outFile.open(QIODevice::WriteOnly)){
            imgObject->save(filePath);
            outFile.close();
            image_edited_not_saved = false;
        }
    }
}

void MainWindow::save(){
    if(image_is_loaded){
        QFile outFile(original_filePath);
        if (outFile.open(QIODevice::WriteOnly)){
            imgObject->save(original_filePath);
            outFile.close();
            QString info = "File saved in\n" + original_filePath;
            QMessageBox::information(this, "Save", info);
            image_edited_not_saved = false;
        }
    }
}

//Hvis bildet er endret skal spørsmål om å lagre dukke opp
bool MainWindow::user_want_to_save(){
    if(image_edited_not_saved){
        QMessageBox::StandardButton show_save_option;
        show_save_option = QMessageBox::question(this, "Save?", "The image is not saved, do you want to save?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(show_save_option == QMessageBox::Yes){
            save_as();
            return false;
        }else if(show_save_option == QMessageBox::No){
            image_edited_not_saved = false;
            return false;
        }
        return true;
    }
    return false;
}

//Får beskjed fra image_wrapper om bildet er originalt eller ikke
void MainWindow::callback_report_image_is_original(){
    image_edited_not_saved = false;
}

/**Laster inn filen via open file dialogen
 * @brief MainWindow::load_file
 * @param fileName
 */
void MainWindow::load_file(const QString &fileName){
    set_image(fileName);
}



/** Setter bilde i vindu når åpnes fra View eller Open
 * @brief MainWindow::set_image
 * @param path
 */
void MainWindow::set_image(const QString &path)
{
    if(!path.isNull() || !path.isEmpty()){
        image_is_loaded = true;
        original_filePath = path;
        imgObject = new QImage();
        imgObject->load(path);

        if(event_listener_set){
            event_listen->on_new_image(*imgObject);   //notify controller by sending reference of the new image
        }
        set_image();

    }
}

/**Fellesmetode som kjøres fra set_updated_image og resize_gui-metoden.
 * Den en gjør er å updatere hele det grafiske interfacet ved endring av bilde.
 * @brief MainWindow::update_gui_resize
 */
void MainWindow::update_gui_resize(){
    scene = new QGraphicsScene(this);
    QSize size(image.width() * zoomVerdi, image.height() * zoomVerdi);
    scene->addPixmap(image.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);

}


/**Benyttes av set_image() når et bilde åpnes for første gang.
 * Den en gjør er å updatere hele det grafiske interfacet.
 * @brief MainWindow::update_gui
 */
void MainWindow::update_gui() {
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());

    if(image.width() > ui->graphicsView->width() || image.height() > ui->graphicsView->height()) {
        ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    }

    ui->graphicsView->setScene(scene);
}


/**Etter et bilde er åpnet, så brukes denne metoden for å updatere og vise i GUI
 * @brief MainWindow::update_imageqt dont update treeview if folder
 * @param updated_image
 */
void MainWindow::set_image() {

    //Viser statistikk
    if(image_is_loaded){
        show_stats(imgObject);
        image = QPixmap::fromImage(*imgObject);
        update_gui();
    }
}


/**Denne metoden for å updatere og vise i GUI et bilde ved endring
 * @brief MainWindow::set_updated_imageqt dont update treeview if folder
 * @param updated_image
 */
void MainWindow::set_updated_image(QImage* updated_image)
{
    imgObject = updated_image;

    //Viser statistikk
    if(image_is_loaded){
        show_stats(imgObject);
        image = QPixmap::fromImage(*imgObject);
        update_gui_resize();
    }
}


/** Setter opp file system view
 * @brief MainWindow::set_fs_view
 */
void MainWindow::set_fs_view()
{
    fs_path = QDir::homePath();
    fs_model = new QFileSystemModel();
    fs_index = fs_model->index(fs_path,0);
    fs_model->setReadOnly(true);
    fs_model->setRootPath(fs_path);

    fs_filter << "*.png" << "*.jpg";
    fs_model->setNameFilters(fs_filter);
    fs_model->setNameFilterDisables(false);
    ui->treeView->setSortingEnabled(true);
    ui->treeView->setModel(fs_model);
    ui->treeView->expand(fs_index);
    ui->treeView->scrollTo(fs_index);
    ui->treeView->setCurrentIndex(fs_index);
    ui->treeView->setColumnWidth(0, 400);
}


// Viser metadata for bilde
void MainWindow::show_stats(QImage *img){
    image_statistics stat;
    ui->textEdit->setText(stat.get_img_stat(*img));
}

// Roterer bilde til venstre
void MainWindow::rotate_left() {
    if(image_is_loaded){
        event_listen->on_clicked_tool(rotateDialog.get_tool());
        connect(&rotateDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
        rotateDialog.rotate_left();
    }
}

// Roterer bilde til høyre
void MainWindow::rotate_right() {
    if(image_is_loaded){
        event_listen->on_clicked_tool(rotateDialog.get_tool());
        connect(&rotateDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
        rotateDialog.rotate_right();
    }
}

// Zoomer inn
void MainWindow::zoomIn() {
    if(image_is_loaded){
        scene = new QGraphicsScene(this);
        ui->actionZoom_Out->setEnabled(true);
        if(zoomVerdi <= zoomRoofValue){
            zoomVerdi += 0.25;
            QSize size(image.width() * zoomVerdi, image.height() * zoomVerdi);
            scene->addPixmap(image.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->graphicsView->setScene(scene);
        }else{
            ui->actionZoom_In->setDisabled(true);
        }
    }
}

// Zoomer ut
void MainWindow::zoomOut() {
    if(image_is_loaded){
        scene = new QGraphicsScene(this);
        ui->actionZoom_In->setEnabled(true);
        if(zoomVerdi >= zoomFloorValue){
            zoomVerdi -= 0.25;
            QSize size(image.width() * zoomVerdi, image.height() * zoomVerdi);
            scene->addPixmap(image.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->graphicsView->setScene(scene);
        }else{
            ui->actionZoom_Out->setDisabled(true);
        }
    }
}


void MainWindow::on_actionActual_size_triggered()
{
    if(image_is_loaded){
        zoomVerdi = 1;
        scene = new QGraphicsScene(this);
        image = QPixmap::fromImage(*imgObject);
        scene->addPixmap(image);
        ui->graphicsView->setScene(scene);
    }
}

void MainWindow::zoomToFit() {
    if(image_is_loaded){
        zoomVerdi = 1;
        scene = new QGraphicsScene(this);
        image = QPixmap::fromImage(*imgObject);
        scene->addPixmap(image);
        scene->setSceneRect(image.rect());
        ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
        ui->graphicsView->setScene(scene);
    }
}


void MainWindow::undo_command(){
    if(image_is_loaded){
        event_listen->undo_last_command();
    }
}

void MainWindow::redo_command(){
    if(image_is_loaded){
        event_listen->redo_last_command();
    }
}


MainWindow::~MainWindow()
{

    delete ui;
    delete imgObject;
    delete imgBackground;
    delete scene;
    delete view;
    delete fs_model;
    delete event_listen;
}


void MainWindow::on_treeView_pressed()
{
    if(!user_want_to_save()){

        if(!fs_model->isDir(ui->treeView->currentIndex())){
            set_image(fs_model->filePath(ui->treeView->currentIndex()));

        }

        /*
       * Det eneste som skal gjøres her at vi oppdasterer indeksen
       * som skal brukes til å gå til neste fil hver gang som
       * vi klikker i filstrukturen.
       */

        pics_in_folder.clear(); //renser vektor fra forrige bruk

        //Først trenge vi få frem hvilken mappe som filen man har klikke på ligger i
        if(!fs_model->isDir(ui->treeView->currentIndex())){
            pic_count_in_dir = 0;
            selected_file = fs_model->filePath(ui->treeView->currentIndex());
            dir_of_selected_file = QFileInfo(selected_file).absoluteDir();

            //Nå kan vi scanne inn alle filer som matcher vår pattern i samme mappe
            dir_of_selected_file.setNameFilters(QStringList() << "*.jpg" << "*.png");
            dir_of_selected_file.setSorting(QDir::IgnoreCase | QDir::Name | QDir::Reversed); //gir samme sorteringsrekkefølge som QFileSystemModel
            dir_of_selected_file.setFilter(QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot);

            QStringList scanned_content = dir_of_selected_file.entryList();
            for(int i=0; i < scanned_content.count(); i++){
                pics_in_folder.push_back(dir_of_selected_file.absoluteFilePath(scanned_content[i]));
                pic_count_in_dir = i+1;
            }

            pic_i=0;

            QString tmp_element = QFileInfo(pics_in_folder[0]).absoluteFilePath(); //starter med første bilde
            QString selected_element = selected_file; //referanse til klikket bilde i filsystemet

            while(tmp_element != selected_element){
                tmp_element = pics_in_folder[pic_i++]; //da har vi funner indeksen
            }
        }

    }//if

}


/**
 * @brief MainWindow::set_event_listener
 * @param l
 * Setter eventlytteren som skal sende events til controller
 */
void MainWindow::set_event_listener(event_listener *l){
    event_listener_set = true;
    event_listen = l;

}


//set-metode for crop-tool
void MainWindow::set_crop_tool(image_tool *t){
    cropDialog.set_tool(t);
    connect(&cropDialog, SIGNAL(signalAccepted()), this, SLOT(execute_value_changed()));
    cropDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
}

callback_iface* MainWindow::get_callback_listener(){
    return this;
}

// set-metdode for brightness-tool
void MainWindow::set_brightness_tool(image_tool *t)
{
    brightnessDialog.set_tool(t);
    connect(&brightnessDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
    connect(&brightnessDialog, SIGNAL(signalAccepted()), this, SLOT(execute_acceptbtn_pressed()));
    connect(&brightnessDialog, SIGNAL(signalCanceled()), this, SLOT(execute_cancelbtn_pressed()));
    brightnessDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
}

// set-metdode for contrast-tool
void MainWindow::set_contrast_tool(image_tool *t)
{
    contrastDialog.set_tool(t);
    connect(&contrastDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
    connect(&contrastDialog, SIGNAL(signalAccepted()), this, SLOT(execute_acceptbtn_pressed()));
    connect(&contrastDialog, SIGNAL(signalCanceled()), this, SLOT(execute_cancelbtn_pressed()));
    contrastDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
}

// set-metdode for rotate-tool
void MainWindow::set_rotate_tool(image_tool *t)
{
    rotateDialog.set_tool(t);
    connect(&rotateDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
    connect(&rotateDialog, SIGNAL(signalAccepted()), this, SLOT(execute_acceptbtn_pressed()));

    rotateDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
}

// set-metdode for blur-tool
void MainWindow::set_blur_tool(image_tool *t) {
    blurDialog.set_tool(t);
    connect(&blurDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
    connect(&blurDialog, SIGNAL(signalAccepted()), this, SLOT(execute_acceptbtn_pressed()));
    connect(&blurDialog, SIGNAL(signalCanceled()), this, SLOT(execute_cancelbtn_pressed()));
    blurDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
}

// set-metdode for color balance tool
void MainWindow::set_color_balance_tool(image_tool *t)
{
    colorBalanceDialog.set_tool(t);
    connect(&colorBalanceDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
    connect(&colorBalanceDialog, SIGNAL(signalAccepted()), this, SLOT(execute_acceptbtn_pressed()));
    connect(&colorBalanceDialog, SIGNAL(signalCanceled()), this, SLOT(execute_cancelbtn_pressed()));
    colorBalanceDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
}

// set-metdode for secure-tool / kryptering
void MainWindow::set_secure_tool(image_tool *t)
{
    encipherDialog.set_tool(t);
    connect(&encipherDialog, SIGNAL(signalImageEncrypted()), this, SLOT(execute_change_and_accept()));
    connect(&encipherDialog, SIGNAL(signalImageDecrypted()), this, SLOT(execute_change_and_accept()));
    encipherDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
    encipherDialog.set_encipher_toggle_on();
}

// set-metdode for auto gamma tool
void MainWindow::set_auto_gamma_tool(image_tool *t)
{
    autoGammaDialog.set_tool(t);
}

// set-metdode for auto level tool
void MainWindow::set_auto_level_tool(image_tool *t)
{
    autoLevelDialog.set_tool(t);
}


// set-metdode for sharpen tool
void MainWindow::set_sharpen_tool(image_tool *t)
{
    sharpnessDialog.set_tool(t);
    connect(&sharpnessDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
    connect(&sharpnessDialog, SIGNAL(signalAccepted()), this, SLOT(execute_acceptbtn_pressed()));
    connect(&sharpnessDialog, SIGNAL(signalCanceled()), this, SLOT(execute_cancelbtn_pressed()));
    sharpnessDialog.setWindowFlags(Qt::WindowStaysOnTopHint);

}

// set-metdode for scale tool
void MainWindow::set_scale_tool(image_tool *t)
{
    scaleDialog.set_tool(t);
    connect(&scaleDialog, SIGNAL(signalValueChanged()), this, SLOT(execute_value_changed()));
    connect(&scaleDialog, SIGNAL(signalAccepted()), this, SLOT(execute_acceptbtn_pressed()));
    connect(&scaleDialog, SIGNAL(signalCanceled()), this, SLOT(execute_cancelbtn_pressed()));
    scaleDialog.setWindowFlags(Qt::WindowStaysOnTopHint);
}


/**Dette er en callback-funksjon for undo/redo-knappene.
 * Når man velger undo/redo sendes kommandoene "ned" og returen kommer hit
 * med rett bilde hentet fra "historie"
 * @brief MainWindow::callback_image_edited
 * @param img
 */
void MainWindow::callback_image_edited(QImage* img){

    set_updated_image(img);
}



/************************
 * Exception handling
 *
 * *********************
 */

/*! Viser en QMessageBox dersom det videresendes en exception fra controller.
 *  Exception som blir sendt hit oppstår direkte i tool klassen som behandler bilde.
 * \brief MainWindow::exception_in_image_processing
 * \param err_title
 * \param err_msg
 */
void MainWindow::exception_in_image_processing(QString err_title, QString err_msg)
{
    QMessageBox::information(this, err_title, err_msg);
}

//End of exception handling


// Slot metoder


/**Felles SLOT som utføres uansett hvilket verktøy som er brukt,
 * og kjøres "live" på bilderedigeringsverktøyene
 */
void MainWindow::execute_value_changed(){
    image_edited_not_saved = true;
    event_listen->updating_image();
}



/**Felles slot som utføres uansett hvilket verktøy som er brukt,
 * men bare når man trykker OK-knappen.
 */
void MainWindow::execute_acceptbtn_pressed(){
    event_listen->finished();
}


/**Felles slot som utføres uansett hvilket verktøy som er brukt,
 * men bare når man trykker Cancel-knappen.
 */
void MainWindow::execute_cancelbtn_pressed(){
    event_listen->canceled();
}

void MainWindow::execute_change_and_accept()
{
    event_listen->updating_image();
    event_listen->finished();
}


void MainWindow::on_blurButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(blurDialog.get_tool());
        event_listen->updating_image();
        blurDialog.exec();
    }
}


void MainWindow::on_brightnessButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(brightnessDialog.get_tool());
        brightnessDialog.exec();

    }
}

void MainWindow::on_cropButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(cropDialog.get_tool());
        cropDialog.exec();
    }
}

void MainWindow::on_contrastButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(contrastDialog.get_tool());
        contrastDialog.exec();
    }
}

void MainWindow::on_rotateButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(rotateDialog.get_tool());
        rotateDialog.exec();
    }
}

void MainWindow::on_colorBalanceButton_clicked()
{
    if(image_is_loaded){
        colorBalanceDialog.prepare_and_run_reset_on_values();
        event_listen->on_clicked_tool(colorBalanceDialog.get_tool());
        colorBalanceDialog.exec();
        colorBalanceDialog.prepare_and_run_reset_on_values();
    }
}

void MainWindow::on_actionAbout_CCIMP_triggered()
{
    aboutDialog.setModal(true);
    aboutDialog.exec();
}

void MainWindow::on_encipherButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(encipherDialog.get_tool());
        encipherDialog.exec();
    }
}

void MainWindow::on_sharpnessButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(sharpnessDialog.get_tool());
        sharpnessDialog.exec();
    }
}

void MainWindow::on_autoGammaButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(autoGammaDialog.get_tool());
        event_listen->updating_image();
        event_listen->finished();
    }
}


void MainWindow::on_autoLevelButton_clicked()
{
    if(image_is_loaded){
        QMessageBox::information(this, "Auto Levels", "<html>Dear user of CCIMP<br>This tool works only with very dark or bright images.</html>");
        event_listen->on_clicked_tool(autoLevelDialog.get_tool());
        event_listen->updating_image();
        event_listen->finished();
    }
}

void MainWindow::on_scaleButton_clicked()
{
    if(image_is_loaded){
        event_listen->on_clicked_tool(scaleDialog.get_tool());
        scaleDialog.set_normal_slider_position();
        scaleDialog.exec();
    }
}


void MainWindow::on_actionNext_triggered()
{
    if(image_is_loaded){
        if(pic_i < pic_count_in_dir -1){
            set_image(pics_in_folder[++pic_i]); //oppdaterer bilde
        }
    }
}

void MainWindow::on_actionPrevoius_triggered()
{
    if(image_is_loaded){
        if(pic_i > 0){
            if(pic_i == pic_count_in_dir) pic_i--;
            set_image(pics_in_folder[--pic_i]);
        }
    }
}


void MainWindow::on_actionReload_triggered()
{
    on_treeView_pressed();
}

// End og slot metoder


void MainWindow::closeEvent(QCloseEvent *){
    user_want_to_save(); //Spør om bruker vil lagre
}


