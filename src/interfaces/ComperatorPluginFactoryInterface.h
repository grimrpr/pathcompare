#ifndef COMPERATORPLUGINFACTORYINTERFACE_H
#define COMPERATORPLUGINFACTORYINTERFACE_H

//Qt includes
#include <QtPlugin>

//Boost includes
#include "boost/shared_ptr.hpp"

//project includes
#include "comperatorplugin.h"

//typedef for shared_ptr reference to ComperatorPlugin
typedef boost::shared_ptr<ComperatorPlugin> ComperatorPluginPtr;

///definition of the plugin interface
class ComperatorPluginFactoryInterface
{
public:
        virtual ~ComperatorPluginFactoryInterface(){}
        //add rosmanager and needed widgets
        virtual ComperatorPluginPtr createComperatorPlugin() const = 0;
        virtual QString getPluginName() const = 0;
};

Q_DECLARE_INTERFACE(ComperatorPluginFactoryInterface,
                    "Pathcompare.ComperatorPluginFactoryInterface/1.0");

#endif // COMPERATORPLUGINFACTORYINTERFACE_H
