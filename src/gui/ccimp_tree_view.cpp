#include "ccimp_tree_view.h"
#include "ui_ccimp_tree_view.h"
#include <QDebug>

ccimp_tree_view::ccimp_tree_view(QWidget *parent) :
    QTreeView(parent),
    ui(new Ui::ccimp_tree_view)
{
    ui->setupUi(this);    


    model = new QDirModel(this);
    model->setReadOnly(true);
    model->setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->treeView->setModel(model);

    on_init();
}

ccimp_tree_view::~ccimp_tree_view()
{
    delete ui;
}

void ccimp_tree_view::on_init()
{
    path = QDir::homePath();
    index = model->index(QDir::homePath());
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);
}

void ccimp_tree_view::on_treeView_clicked(const QModelIndex &index)
{
    qDebug() << ui->treeView->currentIndex();
    qDebug() << model->filePath(ui->treeView->currentIndex());
}
