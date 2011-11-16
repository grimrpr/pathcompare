#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>

class PluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = 0);

Q_SIGNALS:

public Q_SLOTS:

};

#endif // PLUGINMANAGER_H
