#-------------------------------------------------
#
# Project created by QtCreator 2011-09-04T13:35:43
#
#-------------------------------------------------

QT       += core gui

TARGET = Pathcompare
TEMPLATE = app

CONFIG      += no_keywords # so Qt won't #define any non-all-caps `keywords'
#INCLUDEPATH += /usr/local/include/boost/
#macx:LIBS   += /usr/lib/libboost_signals.a  # ...your exact paths may vary

INCLUDEPATH+="/opt/ros/diamondback/stacks/pathcompare/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/common_msgs/nav_msgs/msg_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/common_msgs/nav_msgs/srv_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/vision_opencv/cv_bridge/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/vision_opencv/opencv2/opencv/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/vision_opencv/opencv2/opencv/include/opencv"
INCLUDEPATH+="/opt/ros/diamondback/stacks/common_msgs/sensor_msgs/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/common_msgs/sensor_msgs/msg_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/common_msgs/sensor_msgs/srv_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/common_msgs/geometry_msgs/msg_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/tools/rosbag/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/tools/topic_tools/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/tools/topic_tools/srv_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/tools/rostest/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/utilities/message_filters/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp/msg_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp/srv_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp_serialization/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp_traits/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/utilities/xmlrpcpp/src"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/tools/rosconsole/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/utilities/rostime/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/utilities/cpp_common/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/messages/rosgraph_msgs/msg_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/messages/std_msgs/include"
INCLUDEPATH+="/opt/ros/diamondback/stacks/ros_comm/messages/std_msgs/msg_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/ros/core/roslib/msg_gen/cpp/include"
INCLUDEPATH+="/opt/ros/diamondback/ros/core/roslib/include"
INCLUDEPATH+="/opt/ros/diamondback/ros/tools/rospack"
INCLUDEPATH+="/opt/ros/diamondback/ros/tools/rospack/include"

SOURCES += main.cpp\
        mainwindow.cpp \
    pluginmanager.cpp \
    comperatorplugin.cpp \
    rosmanager.cpp \
    ressourcetreemodel.cpp \
    treeitem.cpp \
    pathcomparemainfactoryplugin.cpp

HEADERS  += mainwindow.h \
    pluginmanager.h \
    ComperatorPluginFactoryInterface.h \
    comperatorplugin.h \
    rosmanager.h \
    ressourcetreemodel.h \
    treeitem.h \
    pathcomparemainfactoryplugin.h

FORMS    += mainwindow.ui



















