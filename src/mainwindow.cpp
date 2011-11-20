//Qt includes
#include <QPluginLoader>
#include <QCoreApplication>
#include <QDir>

//project includes
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interfaces/comperatorplugin.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        ros_mngr(parent)
{
    ui->setupUi(this);

    //DEBUG / TEST:
    QStringList slist = ros_mngr.getTopicNamesOfType("rosgraph_msgs/Log");
    std::cout << slist.at(0).toLocal8Bit().constData() << std::endl;

    //DEBUG / TEST:
    std::cout << ros_mngr.strTopicsAndTypes() << std::endl;

    //DEBUG / TEST
    rtm = new RessourceTreeModel(&ros_mngr, this);
    ui->ResourceView->setModel(rtm);
    ui->ResourceView->show();

    //connect ROSManager with RessourceTreeModel objects
    connect(&ros_mngr, SIGNAL(updateModel()), rtm, SLOT(updateTopic()));

    //DEBUG / TEST
    //load Plugins main and camera view
    QDir plugin_dir("/opt/ros/diamondback/stacks/pathcompareplugins/lib");
    QPluginLoader plugin_loader_main(plugin_dir.absoluteFilePath("libpluginmain.so"));
    QPluginLoader plugin_loader_camera(plugin_dir.absoluteFilePath("libcameraview.so"));

    if(plugin_loader_main.load())
    {
            QObject * object = plugin_loader_main.instance();
            ComperatorPluginFactoryInterface *cpfi = qobject_cast<ComperatorPluginFactoryInterface *>(object);
            if(cpfi){

                    std::cout << "plugin: "
                              << cpfi->getPluginName().toLocal8Bit().constData()
                              << "has been loaded "
                              << std::endl;

                    ComperatorPluginPtr comp_plugin = cpfi->createComperatorPlugin(&ros_mngr, ui->tab);
                    plugin_mngr.addPlugin(comp_plugin);
                    comp_plugin->testFunction();

            }
            else
                qDebug() << "cast to ComperatorPluginFactoryInterface was not possible";
    }
    else
            qDebug() << plugin_loader_main.errorString();

    if(plugin_loader_camera.load())
    {
            QObject * object = plugin_loader_camera.instance();
            ComperatorPluginFactoryInterface *cpfi = qobject_cast<ComperatorPluginFactoryInterface *>(object);
            if(cpfi){

                    std::cout << "plugin: "
                              << cpfi->getPluginName().toLocal8Bit().constData()
                              << "has been loaded "
                              << std::endl;

                    ComperatorPluginPtr comp_plugin = cpfi->createComperatorPlugin(&ros_mngr, ui->tab_2);
                    plugin_mngr.addPlugin(comp_plugin);
                    comp_plugin->testFunction();
            }
            else
                qDebug() << "cast to ComperatorPluginFactoryInterface was not possible";
    }
    else
            qDebug() << plugin_loader_camera.errorString();

}

MainWindow::~MainWindow()
{
        delete ui;
        delete rtm;
}
