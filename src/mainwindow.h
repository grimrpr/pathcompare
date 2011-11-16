#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt includes
#include <QMainWindow>

//std includes
#include <iostream>

//project includes
#include "interfaces/rosmanager.h"
#include "interfaces/comperatorpluginfactoryinterface.h"
#include "ressourcetreemodel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ROSManager ros_mngr;
    RessourceTreeModel *rtm;

};

#endif // MAINWINDOW_H
