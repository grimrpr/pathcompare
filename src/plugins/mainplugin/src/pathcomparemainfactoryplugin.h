#ifndef PATHCOMPAREMAINFACTORYPLUGIN_H
#define PATHCOMPAREMAINFACTORYPLUGIN_H

//QT includes
#include <QObject>

//project includes
//#include "interfaComperatorPluginFactoryInterface.h"
#include "../../../interfaces/comperatorpluginfactoryinterface.h"
#include "../../../interfaces/comperatorplugin.h"


class PathcompareMainFactoryPlugin : public QObject, public ComperatorPluginFactoryInterface
{
        Q_OBJECT
        Q_INTERFACES(ComperatorPluginFactoryInterface)
public:
        explicit PathcompareMainFactoryPlugin(QObject *parent = 0);

        ComperatorPluginPtr createComperatorPlugin() const;
        QString getPluginName() const;

Q_SIGNALS:


public Q_SLOTS:

};


#endif // PATHCOMPAREMAINFACTORYPLUGIN_H
