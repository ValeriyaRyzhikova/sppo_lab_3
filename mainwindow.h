#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileSystemModel>
#include <QMainWindow>
#include <QDir>
#include "abstractcalculation.h"
#include "filecalculation.h"
#include "typecalculation.h"
#include "contentfortable.h"
#include "abstractadapter.h"
#include "tableadapter.h"
#include "abstractchartadapter.h"
#include "piechartadapter.h"
#include "barchartadapter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum ADAPTER{
        TABLE,
        PIE,
        BAR,
        SIZE_ADAPTER
    };
    enum STRATEGY{
        FILE,
        TYPE,
        SIZE_STRATEGY
    };

    QDir currentDir_;
    int currentStategy_;
    int currentAdapter_;
    Ui::MainWindow *ui_;
    QFileSystemModel *dirModel_;
    AbstractCalculation **strategies_;
    AbstractAdapter **adapters_;
    QWidget* bufferWidget_;
    void updateCurrentDir();
    void createStrategy();
    void createAdapters();
    void connectStategyAdapter();
    void disconnectStategyAdapter();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void fillWidget(QWidget *);

    void changeDir(QModelIndex);
    void redefineStrategy(QString);
    void redefineAdapter(QString);
};

#endif // MAINWINDOW_H
