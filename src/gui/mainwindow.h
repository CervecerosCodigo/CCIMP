#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

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
    void showDebugMsg();
    void createConnections();
    void loadFile(const QString &fileName);

    QString filePath;

public slots:
    void open();
};

#endif // MAINWINDOW_H
