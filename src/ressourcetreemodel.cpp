#include "ressourcetreemodel.h"

RessourceTreeModel::RessourceTreeModel(ROSManager *ros_mngr, QObject *parent) :
        QAbstractItemModel(parent),
        rootItem(new TreeItem("topics"))
{
        //fill in the data
        setupModelData(rootItem);
}

RessourceTreeModel::~RessourceTreeModel()
{
        delete rootItem;
}

void RessourceTreeModel::updateModel()
{
        const QStringList topic_types = ros_mngr->getAllTopicTypes();
        QStringList del_types, keep_types;
        QString topic_type_name;

        int num_curr_topics = rootItem->childCount();

        //read model currently in model
        for(int i = 0; i < num_curr_topics; ++i)
        {
                topic_type_name = rootItem->childAt(i)->getData().toString();

                if(topic_types.contains(topic_type_name))
                        keep_types << topic_type_name;
                else
                        del_types << topic_type_name;
        }

        QStringList::ConstIterator it;

        //remove old topics
        for(it = del_types.constBegin();
            it != del_types.constEnd();
            ++it)
        {
                const int idx = rootItem->getIndex(*it);
                beginRemoveRows(index(-1,-1), idx, idx);
                rootItem->removeChildAt(idx);
                endRemoveRows();
        }


        //update topic type names
        for(it = topic_types.constBegin();
            it != topic_types.constEnd();
            ++it)
        {
                //keep this topic type
                //but we need to update the children
                if(keep_types.contains(*it))
                {
                        //update current topics of type
                        TreeItem * current_type = rootItem->childAt(rootItem->getIndex(*it));
                        QStringList topic_names = ros_mngr->getTopicNamesOfType((*it).toStdString());

                        int num_curr_topics = current_type->childCount();
                        const int idx = rootItem->getIndex(*it);

                        //check topics currently in model
                        for(int i = 0; i < num_curr_topics; ++i)
                        {
                                topic_type_name = current_type->childAt(i)->getData().toString();

                                if(topic_names.contains(topic_type_name))
                                        topic_names.removeOne(topic_type_name);
                                else
                                {
                                        int pos = current_type->getIndex(topic_type_name);
                                        beginRemoveRows(index(idx,0), pos, pos);
                                        current_type->removeChildAt(pos);
                                        endRemoveRows();
                                        topic_names.removeOne(topic_type_name);
                                }
                        }

                        //add remaining new types
                        QStringList::ConstIterator ci;
                        for(ci = topic_names.constBegin();
                            ci != topic_names.constEnd();
                            ++ci)
                        {
                                int pos = current_type->childCount();
                                TreeItem *new_child = new TreeItem(*ci, current_type);
                                beginInsertRows(index(idx,0), pos, pos);
                                current_type->appendChild(new_child);
                                endInsertRows();
                        }
                }

                //add this topic type
                else
                {
                        TreeItem * new_item = new TreeItem(*it, rootItem);
                        QStringList topic_names = ros_mngr->getTopicNamesOfType((*it).toStdString());
                        QStringList::ConstIterator new_topic;

                        for(new_topic = topic_names.constBegin();
                            new_topic != topic_names.constEnd();
                            ++new_topic)
                        {
                                TreeItem *new_child = new TreeItem(*new_topic, new_item);
                                new_item->appendChild(new_child);
                        }

                        const int idx = rootItem->childCount();
                        beginInsertRows(index(-1,-1), idx, idx);
                        rootItem->appendChild(new_item);
                        endInsertRows();
                }
        }
}


void RessourceTreeModel::setupModelData(TreeItem * root)
{
        QStringList topic_types(ros_mngr->getAllTopicTypes());

        QStringList::const_iterator it;
        for(it = topic_types.constBegin(); it != topic_types.constEnd(); ++it)
        {

                QStringList topic_names(ros_mngr->getTopicNamesOfType((*it).toStdString()));

                TreeItem * new_type_item = new TreeItem(*it, root);
                root->appendChild(new_type_item);

                QStringList::const_iterator topic_names_it;
                for(topic_names_it = topic_names.constBegin();
                    topic_names_it != topic_names.constEnd();
                    ++topic_names_it)
                {
                        TreeItem * new_topic_item = new TreeItem(*topic_names_it,
                                                                 new_type_item);

                        new_type_item->appendChild(new_topic_item);
                }
        }
}


QVariant RessourceTreeModel::data(const QModelIndex &index, int role) const
{
        //DEBUG
        qDebug() << "data()";

        if(!index.isValid())
                return QVariant();

        if(role != Qt::DisplayRole)
                return QVariant();

        TreeItem *ti = static_cast<TreeItem *>(index.internalPointer());

        return ti->getData();
}


Qt::ItemFlags RessourceTreeModel::flags(const QModelIndex &index) const
{
        //DEBUG
        qDebug() << "flags()";

        if(!index.isValid())
                return 0;

        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant RessourceTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
        //DEBUG
        qDebug() << "headerData()";

    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->getData();

    return QVariant();
}

QModelIndex RessourceTreeModel::index(int row, int column, const QModelIndex &parent) const
{

        //DEBUG
        qDebug() << "index()";

        if(!hasIndex(row, column, parent))
                return QModelIndex();

        TreeItem *parentItem;

        if(!parent.isValid())
                parentItem = rootItem;
        else
                parentItem = static_cast<TreeItem *>(parent.internalPointer());

        TreeItem * childItem = parentItem->childAt(row);

        if(childItem)
                return createIndex(row, column, childItem);
        else
                return QModelIndex();
}


QModelIndex RessourceTreeModel::parent(const QModelIndex &index) const
{
        //DEBUG
        qDebug() << "parent()";

        if(!index.isValid())
                return QModelIndex();

        TreeItem *child_item = static_cast<TreeItem*>(index.internalPointer());
        TreeItem *parent_item = child_item->parent();

        if (parent_item == rootItem)
            return QModelIndex();

        return createIndex(parent_item->row() , 0, parent_item);
}

int RessourceTreeModel::rowCount(const QModelIndex &parent) const
{
        //DEBUG
        qDebug() << "rowCount()";
        TreeItem *parentItem;

        if(parent.column() > 0)
                return 0;


        if(!parent.isValid())
                parentItem = rootItem;

        else
                parentItem = static_cast<TreeItem *>(parent.internalPointer());

        return parentItem->childCount();
}

int RessourceTreeModel::columnCount(const QModelIndex &parent) const
{
        return 1;
}

void RessourceTreeModel::updateTopic()
{
        //DEBUG
        qDebug() << "updateTopic (signal received)";

        /*
        TreeItem * temp = new TreeItem("topics");
        TreeItem * change = rootItem;

        setupModelData(temp);

        beginResetModel();
        rootItem = temp;
        endResetModel();

        delete change;
        */

        updateModel();
}
