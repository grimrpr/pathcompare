#include "pathcomparemainfactoryplugin.h"
#include "../../interfaces/rosmanager.h"


PathcompareMainFactoryPlugin::PathcompareMainFactoryPlugin(QObject *parent) :
    QObject(parent)
{
}

ComperatorPluginPtr PathcompareMainFactoryPlugin::createComperatorPlugin(ROSManager *ros_manager) const
{
        QStringList sl = ros_manager->getAllTopicTypes();
        qDebug() << sl.first();
        ComperatorPluginPtr comp_plugin(new ComperatorPlugin());
        return comp_plugin;
}

QString PathcompareMainFactoryPlugin::getPluginName() const
{
        return QString("Main Compare");
}

Q_EXPORT_PLUGIN2(libmainplugin, PathcompareMainFactoryPlugin)
