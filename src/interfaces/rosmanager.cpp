#include "rosmanager.h"

ROSManager::ROSManager(QObject *parent) :
        QThread(parent),
        nh(),
        shutdown(false),
        topic_timer(this)
{
        this->start();

        //start refresh timer
        connect(&topic_timer, SIGNAL(timeout()), this, SLOT(refresh()));
        topic_timer.start(1000);

}

void ROSManager::refresh()
{
        //DEBUG
        qDebug() << "refresh";
        Q_EMIT updateModel();
}

ros::master::V_TopicInfo ROSManager::getAllTopicsAndTypes() const
{
        ros::master::V_TopicInfo v;
        ros::master::getTopics(v);

        return v;
}


QStringList ROSManager::getAllTopicTypes() const
{

        QStringList result;
        ros::master::V_TopicInfo v;
        ros::master::getTopics(v);

        //only add topics of type type_name to result
        BOOST_FOREACH(ros::master::TopicInfo &topic_info, v) {
                if(!result.contains(topic_info.datatype.c_str()))
                {
                        result << topic_info.datatype.c_str();
                }
        }

        return result;
}


QStringList ROSManager::getTopicNamesOfType(const std::string &type_name) const
{
        QStringList result;
        ros::master::V_TopicInfo v;
        ros::master::getTopics(v);

        //only add topics of type type_name to result
        BOOST_FOREACH(ros::master::TopicInfo &topic_info, v) {
                if(type_name == topic_info.datatype)
                {
                        result << topic_info.name.c_str();
                }
        }

        return result;
}

std::string ROSManager::strTopicsAndTypes() const
{
        std::stringstream out;
        ros::master::V_TopicInfo v;
        ros::master::getTopics(v);

        BOOST_FOREACH(ros::master::TopicInfo &topic_info, v) {
                out << "\ttopic name: " << topic_info.name;
                out << "\t\ttopic type: " << topic_info.datatype;
                out << std::endl;
        }

        return out.str();
}


template <class M>
boost::shared_ptr<message_filters::Cache<M> > ROSManager::subscribeToTopic(const std::string &topicname, const unsigned int cachesize, const ComperatorPlugin &caller)
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


template <class M>
void ROSManager::unsubscribeFromTopic(const std::string &topicname, const ComperatorPlugin &comp_plugin)
{
        //TODO: delete and unsubscribe if necessary
}

void ROSManager::run()
{
        while(ros::ok() && !shutdown){
                ros::spin();
        }
}
