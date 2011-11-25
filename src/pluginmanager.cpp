#include "pluginmanager.h"

PluginManager::PluginManager(const QDir &searchdir, QTabWidget *tw, ROSManager * ros_manager, QObject *parent) :
    QObject(parent),
        plugin_dir(searchdir),
        tab_widget(tw),
        ros_mngr(ros_manager)
{
        tw->clear();

        //only look at lib files
        QStringList strl;
        strl << "*.so" << "*.dll" << "*.sl";
        plugin_dir.setNameFilters(strl);

}

void PluginManager::addPlugin(const ComperatorPluginPtr &comparator)
{
        plugin_list << comparator;
}

void PluginManager::updatePlugins()
{

        QStringList new_plugin_list = plugin_dir.entryList();

        QStringList::ConstIterator it;
        for(it = new_plugin_list.constBegin(); it < new_plugin_list.constEnd(); ++it)
        {
                //plugin has not been loaded yet
                if(!plugin_names_list.contains(*it))
                {
                        //try to load plugin
                    //load all plugins found in plugin_dir and add them a tab in tw
                    QPluginLoader plugin_loader_main(plugin_dir.absoluteFilePath(*it));

                    if(plugin_loader_main.load())
                    {
                            QObject * object = plugin_loader_main.instance();
                            ComperatorPluginFactoryInterface *cpfi = qobject_cast<ComperatorPluginFactoryInterface *>(object);
                            if(cpfi){
                                    //add new tab
                                    int tab_index = tab_widget->insertTab(0,new QWidget(), cpfi->getPluginName());

                                    plugin_names_list << *it;

                                    //set tab text to plugin name
                                    tab_widget->setTabText(tab_index, cpfi->getPluginName());

                                    std::cout << "plugin: "
                                              << cpfi->getPluginName().toLocal8Bit().constData()
                                              << "has been loaded "
                                              << std::endl;

                                    ComperatorPluginPtr comp_plugin = cpfi->createComperatorPlugin(ros_mngr,
                                                                                                   tab_widget->widget(tab_index));
                                    plugin_list << comp_plugin;

                            }
                            else
                                    qDebug() << "cast to ComperatorPluginFactoryInterface was not possible";
                    }
                    else
                            qDebug() << plugin_loader_main.errorString();

                }
        }
}
