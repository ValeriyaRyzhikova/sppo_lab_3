#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    bufferWidget_ = ui_->widget;
    firstWidget_ = ui_->widget;
    QString homePath = QDir::homePath();
    currentDir_= QDir("*");

    dirModel_ =  new QFileSystemModel(this);
    dirModel_->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel_->setRootPath(homePath);
    ui_->treeView->setModel(dirModel_);

    for (int i = 1; i < dirModel_->columnCount(); ++i)
    ui_->treeView->hideColumn(i);

    currentStategy_=FILE;
    currentAdapter_=TABLE;

    createStrategy();
    createAdapters();
    connectStategyAdapter();

}

void MainWindow::createStrategy()
{
    strategies_ = new AbstractCalculation*[SIZE_STRATEGY];
    strategies_[FILE]=new FileCalculation();
    strategies_[TYPE]=new TypeCalculation();
}

void MainWindow::createAdapters()
{
    adapters_ = new AbstractAdapter*[SIZE_ADAPTER];
    adapters_ [TABLE]=new TableAdapter();
    adapters_ [PIE]=new PieChartAdapter();
    adapters_ [BAR]=new BarChartAdapter();
}

void MainWindow::connectStategyAdapter()
{
    for(int j=0; j<SIZE_STRATEGY; j++)
        QObject::connect(strategies_[j], &AbstractCalculation::sentAdapter,
                     adapters_[currentAdapter_], &AbstractAdapter::updateAdapter);
    QObject::connect(adapters_[currentAdapter_], &AbstractAdapter::sentMainwindow,
                     this, &MainWindow::fillWidget);

}

void MainWindow::disconnectStategyAdapter()
{
    for(int j=0; j<SIZE_STRATEGY; j++)
        QObject::disconnect(strategies_[j], &AbstractCalculation::sentAdapter,
                     adapters_[currentAdapter_], &AbstractAdapter::updateAdapter);
    QObject::disconnect(adapters_[currentAdapter_], &AbstractAdapter::sentMainwindow,
                     this, &MainWindow::fillWidget);

}


MainWindow::~MainWindow()
{
    delete ui_;
    delete dirModel_;
    delete firstWidget_;

    for(int i=0; i<SIZE_ADAPTER; i++)
        delete adapters_[i];
    delete []adapters_;

    for(int i=0; i<SIZE_STRATEGY; i++)
        delete strategies_[i];
    delete [] strategies_;
}

void MainWindow::changeDir(QModelIndex index)
{
    currentDir_ = QDir(dirModel_->filePath(index));
    updateCurrentDir();
}

void MainWindow::updateCurrentDir()
{
    if (currentDir_.exists())
        strategies_[currentStategy_]->execute(currentDir_);
}

void MainWindow::redefineStrategy(QString strategy)
{
    if (strategy=="Type")
        currentStategy_=TYPE;
    else{
        currentStategy_=FILE;
    }
    updateCurrentDir();
}

void MainWindow::redefineAdapter(QString adapter)
{
    disconnectStategyAdapter();
    if (adapter=="Table")
        currentAdapter_=TABLE;
    else if (adapter=="Bar"){
        currentAdapter_=BAR;
    }
    else if (adapter=="Pie"){
        currentAdapter_=PIE;
    }
    connectStategyAdapter();
    strategies_[currentStategy_]->bringUpSentAdapter();
}

void MainWindow::fillWidget(QWidget *widget)
{
    if (bufferWidget_ != widget){
        QLayoutItem *temp = ui_->layoutForWidget->replaceWidget(bufferWidget_, widget);
        bufferWidget_->setParent(NULL);
        bufferWidget_ = widget;
        delete temp;
    }
}
