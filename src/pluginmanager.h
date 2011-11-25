#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

//Qt includes
#include <QObject>
#include <QList>
#include <QDir>
#include <QTabWidget>
#include <QPluginLoader>

//project includes
#include "interfaces/comperatorplugin.h"
#include "interfaces/comperatorpluginfactoryinterface.h"

class PluginManager : public QObject
{
        Q_OBJECT
        QList<ComperatorPluginPtr> plugin_list;
        QList<QString> plugin_names_list;
        QDir plugin_dir;
        QTabWidget *tab_widget;

public:
        explicit PluginManager(const QDir &searchdir, QTabWidget * tw, QObject *parent = 0);
        void addPlugin(const ComperatorPluginPtr &comparator);

Q_SIGNALS:

public Q_SLOTS:
        void updatePlugins();

};

#endif // PLUGINMANAGER_H
