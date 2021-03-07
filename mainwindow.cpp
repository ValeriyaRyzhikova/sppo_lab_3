#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    QString homePath = QDir::homePath();

    dirModel_ =  new QFileSystemModel(this);
    dirModel_->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel_->setRootPath(homePath);
    ui_->treeView->setModel(dirModel_);

    for (int i = 1; i < dirModel_->columnCount(); ++i)
    ui_->treeView->hideColumn(i);

    ui_->tableView->verticalHeader()->setVisible(false);
    strategy_ = new FileCalculation();
    contentTable_ = new ContentForTableView();
    setTableView();

}

MainWindow::~MainWindow()
{
    delete ui_;
    delete contentTable_;
    delete strategy_;
    delete dirModel_;
}

void MainWindow::changeDir(QModelIndex index)
{
    currentDir_ = QDir(dirModel_->filePath(index));
    updateCurrentDir();
}

void MainWindow::updateCurrentDir()
{
    contentTable_->updateContent(strategy_->execute(currentDir_));
}

void MainWindow::setTableView(){
    ui_->tableView->setModel(contentTable_);
    ui_->tableView->setColumnWidth(0,380);
    ui_->tableView->setColumnWidth(1,70);
}

void MainWindow::redefineStrategy(QString strategy)
{
    delete strategy_;
    if (strategy=="Type")
        strategy_ = new TypeCalculation();
    else{
        strategy_ = new FileCalculation();
    }
    updateCurrentDir();
}
