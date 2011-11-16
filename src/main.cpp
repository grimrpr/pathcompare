//Qt includes
#include <QtGui/QApplication>

//ROS includes
#include "ros/ros.h"

//project includes
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ros::init(argc, argv, "pathcompare");
    MainWindow w;
    w.show();

    return a.exec();
}
