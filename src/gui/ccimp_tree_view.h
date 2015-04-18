#ifndef CCIMP_TREE_VIEW_H
#define CCIMP_TREE_VIEW_H

#include <QTreeView>
#include <QModelIndex>
#include <QDir>
#include <QDirModel>

namespace Ui {
class ccimp_tree_view;
}

class ccimp_tree_view : public QTreeView
{
    Q_OBJECT

public:
    explicit ccimp_tree_view(QWidget *parent = 0);
    ~ccimp_tree_view();


private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::ccimp_tree_view *ui;
    QDirModel *model;
    QString path;
    QModelIndex index;
    void on_init();


};

#endif // CCIMP_TREE_VIEW_H
