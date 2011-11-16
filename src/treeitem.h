#ifndef TREEITEM_H
#define TREEITEM_H

//Qt includes
#include <QVariant>

class TreeItem
{
public:
        TreeItem(QString data, TreeItem *parent = 0);
        ~TreeItem();

        QVariant getData() const;
        TreeItem * parent() const;
        TreeItem * childAt(int i) const;
        QList<TreeItem *> allChildren() const;

        int getIndex(QString topic_name)const ;
        int childCount() const;
        int row() const;

        void removeChildAt(int i);
        void appendChild(TreeItem *);

protected:
        QString data;
        TreeItem * parentItem;
        QList<TreeItem *> children;
};


#endif // TREEITEM_H
