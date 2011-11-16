#include "treeitem.h"

TreeItem::TreeItem(QString data, TreeItem *parent) :
        data(data),
        parentItem(parent),
        children()
{}


TreeItem::~TreeItem()
{
        qDeleteAll(children);
}


QVariant TreeItem::getData() const
{
        return QVariant(data);
}


TreeItem * TreeItem::parent() const
{
        return parentItem;
}


TreeItem * TreeItem::childAt(int i) const
{
        return children.at(i);
}


QList<TreeItem *> TreeItem::allChildren() const
{
        return children;
}


int TreeItem::getIndex(QString topic_name) const
{
        int result = 0;

        QList<TreeItem *>::const_iterator it;
        for(it = children.constBegin(); it != children.constEnd(); ++it)
        {
                if((*it)->getData().toString() == topic_name)
                        break;
                ++result;
        }

        if(result >= childCount())
                return -1;

        return result;
}


int TreeItem::childCount() const
{
        return children.size();
}


int TreeItem::row() const
{
        if(parentItem)
                return parentItem->children.indexOf(const_cast<TreeItem *>(this));
        return 0;
}


void TreeItem::removeChildAt(int i)
{
        children.removeAt(i);
}

void TreeItem::appendChild(TreeItem * child)
{
        return children.append(child);
}

