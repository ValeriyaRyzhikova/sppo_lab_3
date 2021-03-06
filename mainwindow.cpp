#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString homePath = QDir::homePath();
    // Определим  файловой системы:
    dirModel_ =  new QFileSystemModel(this);
    dirModel_->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel_->setRootPath(homePath);


    ui->treeView->setModel(dirModel_);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeDir(QModelIndex index)
{
    currentDir_ = QDir(dirModel_->filePath(index));
}
