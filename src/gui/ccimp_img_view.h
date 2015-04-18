#ifndef CCIMP_IMG_VIEW_H
#define CCIMP_IMG_VIEW_H

#include <QWidget>
#include <QImage>
#include <QGraphicsView>
#include <QDebug>

namespace Ui {
class ccimp_img_view;
}

class ccimp_img_view : public QGraphicsView
{
    Q_OBJECT

public:
    explicit ccimp_img_view(QWidget *parent = 0);
    void openImage();
    ~ccimp_img_view();

private:
    Ui::ccimp_img_view *ui;
    QString imgPath;
    QImage *imgObject;
    QPixmap image;
    QGraphicsScene *scene;
    QGraphicsView *view;
    //QGraphicsPixmapItem *item; //Bruke ikke foreløpig

};

#endif // CCIMP_IMG_VIEW_H
