#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    QString homePath = QDir::homePath();
    currentDir_= QDir("*");

    dirModel_ =  new QFileSystemModel(this);
    dirModel_->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel_->setRootPath(homePath);
    ui_->treeView->setModel(dirModel_);

    for (int i = 1; i < dirModel_->columnCount(); ++i)
    ui_->treeView->hideColumn(i);

    strategy_ = new FileCalculation();
    adapter_=new TableAdapter();
    QObject::connect(strategy_, &AbstractCalculation::sentAdapter,
                     adapter_, &AbstractAdapter::updateAdapter);

    QObject::connect(adapter_, &AbstractAdapter::sentMainwindow,
                     this, &MainWindow::fillWidget);

}

MainWindow::~MainWindow()
{
    delete ui_;
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
    if (currentDir_.exists())
        strategy_->execute(currentDir_);
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

void MainWindow::fillWidget(QWidget *widget)
{
    //ui_->widget=widget;
    ui_->layoutForWidget->replaceWidget(ui_->widget, widget);
}
