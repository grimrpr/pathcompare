#include "pluginmanager.h"

PluginManager::PluginManager(QObject *parent) :
    QObject(parent)
{
}

void PluginManager::addPlugin(const ComperatorPluginPtr &comparator)
{
        plugins << comparator;
}
