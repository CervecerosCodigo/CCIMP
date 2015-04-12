#include "ccimp_tree_view.h"
#include "ui_ccimp_tree_view.h"

ccimp_tree_view::ccimp_tree_view(QWidget *parent) :
    QTreeView(parent),
    ui(new Ui::ccimp_tree_view)
{
    ui->setupUi(this);    


    model = new QDirModel(this);
    model->setReadOnly(true);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->treeView->setModel(model);


    QString path = QDir::homePath();
    QModelIndex index = model->index(QDir::homePath());

    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);

}

ccimp_tree_view::~ccimp_tree_view()
{
    delete ui;
}
