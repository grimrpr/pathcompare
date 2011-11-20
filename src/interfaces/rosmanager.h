#ifndef ROSMANAGER_H
#define ROSMANAGER_H


//Boost includes
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>
//#define foreach BOOST_FOREACH

//STL includes
#include <string>
#include <iostream>
#include <map>

//ROS includes
#include "ros/ros.h"
#include "ros/node_handle.h"
#include "ros/master.h"
#include "message_filters/subscriber.h"
#include "message_filters/cache.h"

//Qt includes
#include <QObject>
#include <QStringList>
#include <QThread>
#include <QTimer>
#include <QDebug>

//project includes
#include "comperatorplugin.h"


/**
  This class handles all ROS specific tasks like initialization and receiving messages from topics.
  In this context each ComperatorPlugin should use ROSManager members to obtain access to desired topics.
  It is also responsible for updating the resource view.
  */
class ROSManager : public QThread
{
    Q_OBJECT
public:
        /**
          This constructor sets up a NodeHandle object.
          */
    explicit ROSManager(QObject *parent = 0);

        //TODO create constructor where running thread is stopped
        //meaning: attribute	shutdown <- true

        /**
          Returns a vector of TopicInfo structures
          @return V_TopicInfo contains TopicInfo structures that describe all topics available from the ROS master
          */
        ros::master::V_TopicInfo getAllTopicsAndTypes() const;

        QStringList getAllTopicTypes() const;

        /**
          Returns a list of topicnames of a specific type.
          @param typename 		topics of the given type shall be listet
          @return QStringList of all available topicnames of given type
          */
        QStringList getTopicNamesOfType(const std::string &type_name) const;

        /**
          Debug function used to get a topic information string ready to be printed.
          @return returns a string with topic information (topicname and topictype)
          */
         std::string strTopicsAndTypes() const;

        /**
          This function is used by ComperatorPlugin instances to subscribe to a desired topic.
          @param topicname		specifies the desired topic to subscibe to
          @param caller			reference to the caller
          @param message_callback 	a functor that will be passed to the subsciber and is executet when messages of type M are received
          @return returns a Pointer to a message_filter::cache after successful subscription otherwise null
          */
        template <class M>
        boost::shared_ptr<message_filters::Cache<M> > subscribeToTopic(const std::string &topicname, const unsigned int cachesize, ComperatorPlugin *caller)
        {

                //TODO: cachesize needs to be set to max value of all plugins
                //topic already subscribed?
                if(!topic_cache_map.count(topicname))
                {
                        //go here if not subscribed yet

                        boost::shared_ptr<message_filters::Subscriber<M> > sub ( new message_filters::Subscriber<M> (nh, topicname, 1));

                        //need to strip type information to hold the reference
                        boost::shared_ptr<void> cache(new message_filters::Cache<M>(*sub, cachesize));
                        topic_cache_map[topicname] = std::make_pair(boost::static_pointer_cast<void>(sub), cache);
                        return boost::static_pointer_cast<message_filters::Cache<M> >(cache);
                }

                else
                {
                        return boost::static_pointer_cast<message_filters::Cache<M> >(topic_cache_map[topicname].second);
                }
        }

        /**
          Unsubscribes from a topic.
          All plugins should call this when a topic should be unsubscribed
          @param topicname specifies the desired topic to unsubscibe from
          @param comp_plugin reference to the caller
          */
        template <class M>
        void unsubscribeFromTopic(const std::string &topicname, const ComperatorPlugin &comp_plugin);

protected:
        /**
          ROS main loop will spin in this separate thread.
          */
        void run();

Q_SIGNALS:
        void newTopicAvailable(ros::master::TopicInfo topic_info);
        void updateModel();

public Q_SLOTS:
        /**
          This slot is invoked at a constant rate to refresh the topic information
          */
        void refresh();

private:
        ros::NodeHandle nh;

        ///end ros
        bool shutdown;

        ///a timer that fires constantly to refresh the resource tree view
        QTimer topic_timer;

        //TODO: what happens with callbacks on unsubscribe?
        ///this map holds subscribed topics, that are associated with a corresponding message_filter::cache of abitrary type M
        ///std::map<std::string, std::pair< boost::shared_ptr::<message_filters::Subscriber<M> >, boost::shared_ptr<message_filters::Cache<M> > >  topic_cache_map;
        ///we need to strip type information to store all possible message types within the ROSManager
        std::map<std::string, std::pair<boost::shared_ptr<void>, boost::shared_ptr<void> > >  topic_cache_map;



};

#endif //ROSMANAGER_H
