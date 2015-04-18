#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "ccimp_tree_view.h"

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
    ccimp_tree_view *ccimp_t;
    void createConnections();
    void loadFile(const QString &fileName);

    QString filePath;

public slots:
    void open();
    void showDebugMsg();
};

#endif // MAINWINDOW_H
