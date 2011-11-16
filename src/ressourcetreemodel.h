#ifndef RESSOURCETREEMODEL_H
#define RESSOURCETREEMODEL_H

//Qt includes
#include <QDebug>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
//#include <QStringList>
#include <QList>

//boost includes
#include <boost/shared_ptr.hpp>

//std includes
#include <string>
#include <map>

//project includes
#include "interfaces/rosmanager.h"
#include "treeitem.h"

class RessourceTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    RessourceTreeModel(ROSManager *ros_mngr, QObject *parent = 0);
    ~RessourceTreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //bool insertRows(int row, int count, const QModelIndex &parent);
    //bool removeRows(int row, int count, const QModelIndex &parent);
    void updateModel();



public Q_SLOTS:
    void updateTopic();

private:
    void setupModelData(TreeItem * new_root);
    int getIndex(const QString topic_type) const;

    ROSManager *ros_mngr;
    TreeItem *rootItem;

};

#endif // RESSOURCETREEMODEL_H
