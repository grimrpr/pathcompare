#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

//Qt includes
#include <QObject>
#include <QList>

//project includes
#include "interfaces/comperatorplugin.h"
#include "interfaces/comperatorpluginfactoryinterface.h"

class PluginManager : public QObject
{
        Q_OBJECT
        QList<ComperatorPluginPtr> plugins;

public:
        explicit PluginManager(QObject *parent = 0);
        void addPlugin(const ComperatorPluginPtr &comparator);

Q_SIGNALS:

public Q_SLOTS:

};

#endif // PLUGINMANAGER_H
