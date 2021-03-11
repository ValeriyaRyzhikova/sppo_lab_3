#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileSystemModel>
#include <QMainWindow>
#include <QDir>
#include "abstractcalculation.h"
#include "filecalculation.h"
#include "typecalculation.h"
#include "contentfortableview.h"
#include "abstractadapter.h"
#include "tableadapter.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QDir currentDir_;
    Ui::MainWindow *ui_;
    QFileSystemModel *dirModel_;
    AbstractCalculation *strategy_;
    AbstractAdapter *adapter_;
    void updateCurrentDir();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void fillWidget(QWidget *);

    void changeDir(QModelIndex);
    void redefineStrategy(QString);
};

#endif // MAINWINDOW_H
