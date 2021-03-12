#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    bufferWidget = ui_->widget;
    QString homePath = QDir::homePath();
    currentDir_= QDir("*");

    dirModel_ =  new QFileSystemModel(this);
    dirModel_->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel_->setRootPath(homePath);
    ui_->treeView->setModel(dirModel_);

    for (int i = 1; i < dirModel_->columnCount(); ++i)
    ui_->treeView->hideColumn(i);

    currentStategy=FILE;
    currentAdapter=TABLE;

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
}

void MainWindow::connectStategyAdapter()
{
    for(int j=0; j<SIZE_STRATEGY; j++)
        QObject::connect(strategies_[j], &AbstractCalculation::sentAdapter,
                     adapters_[currentAdapter], &AbstractAdapter::updateAdapter);
    QObject::connect(adapters_[currentAdapter], &AbstractAdapter::sentMainwindow,
                     this, &MainWindow::fillWidget);

}

void MainWindow::disconnectStategyAdapter()
{
    for(int j=0; j<SIZE_STRATEGY; j++)
        QObject::disconnect(strategies_[j], &AbstractCalculation::sentAdapter,
                     adapters_[currentAdapter], &AbstractAdapter::updateAdapter);
    QObject::disconnect(adapters_[currentAdapter], &AbstractAdapter::sentMainwindow,
                     this, &MainWindow::fillWidget);

}


MainWindow::~MainWindow()
{
    delete ui_;
    delete dirModel_;
    delete bufferWidget;

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
        strategies_[currentStategy]->execute(currentDir_);
}

void MainWindow::redefineStrategy(QString strategy)
{
    if (strategy=="Type")
        currentStategy=TYPE;
    else{
        currentStategy=FILE;
    }
    updateCurrentDir();
}

void MainWindow::redefineAdapter(QString adapter)
{
    disconnectStategyAdapter();
    if (adapter=="Table")
        currentAdapter=TABLE;
    else{
        currentAdapter=PIE;
    }
    connectStategyAdapter();
    updateCurrentDir();
}

void MainWindow::fillWidget(QWidget *widget)
{
    //ui_->layoutForWidget->update();

    //ui_->layoutForWidget->removeWidget(ui_->widget);
    //ui_->layoutForWidget->addWidget(widget);
    if (bufferWidget != widget){
        QLayoutItem *temp = ui_->layoutForWidget->replaceWidget(bufferWidget, widget);
        //temp->layout()->removeWidget(bufferWidget);//temp->setGeometry(QRect(2000,2000,0,0));
        bufferWidget->setParent(NULL);
        bufferWidget = widget;
        delete temp;
    }
    //ui_->layoutForWidget->replaceWidget(firstWidget, widget);
    //ui_->layoutForWidget->update();
    //ui_->layoutForWidget->replaceWidget(firstWidget, widget);
    //ui_->layoutForWidget->replaceWidget(ui_->widget, 0);
    //ui_->layoutForWidget->update();
}
