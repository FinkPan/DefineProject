#include "coordinate_system_model.hpp"
#include "coordinate_system_item.hpp"

CoordinateSystemModel::CoordinateSystemModel(QObject *parent)
  : QAbstractItemModel(parent)
{
  root_item_ = new CoordinateSystemItem("root");
  CoordinateSystemItem *test1 = new CoordinateSystemItem("test1",root_item_);
  CoordinateSystemItem *gcs_item_ = new CoordinateSystemItem("gcs_item_",test1);
  CoordinateSystemItem *test2 = new CoordinateSystemItem("test2",test1);
  test2->setCoordinatieSystem();
  CoordinateSystemItem *test3 = new CoordinateSystemItem("test3",root_item_);
  CoordinateSystemItem *test4 = new CoordinateSystemItem("test4",test2);
  test4->setCoordinatieSystem();

  QVariant columnData("test1");
  root_item_->appendChild(test1);
  QVariant columnData3("test3");
  root_item_->appendChild(test3);
  test1->appendChild(gcs_item_);
  test1->appendChild(test2);
  test2->appendChild(test4);
}

CoordinateSystemModel::~CoordinateSystemModel()
{
  delete root_item_;
}

QVariant CoordinateSystemModel::data(const QModelIndex &index,int role) const
{
  if(!index.isValid())
    return QVariant();

  if(role != Qt::DisplayRole)
      return QVariant();

  CoordinateSystemItem *item = 
    static_cast<CoordinateSystemItem*>(index.internalPointer());

  return item->data();
}

CoordinateSystemItem* CoordinateSystemModel::getItem(const QModelIndex &index) const
{
  return static_cast<CoordinateSystemItem*>(index.internalPointer());
}


QModelIndex CoordinateSystemModel::index(int row,int column,
                  const QModelIndex &parent) const 
{
  if(!hasIndex(row,column,parent))
      return QModelIndex();

  CoordinateSystemItem *parentItem;

  if(!parent.isValid())
      parentItem = root_item_;
  else
      parentItem = static_cast<CoordinateSystemItem*>(parent.internalPointer());

  CoordinateSystemItem *childItem = parentItem->child(row);
  if(childItem)
      return createIndex(row,column,childItem);
  else
      return QModelIndex();
}
QModelIndex CoordinateSystemModel::parent(const QModelIndex &index) const 
{
  if(!index.isValid())
    return QModelIndex();

  CoordinateSystemItem *childItem = 
    static_cast<CoordinateSystemItem*>(index.internalPointer());
  CoordinateSystemItem *parentItem = childItem->parentItem();

  if(parentItem == root_item_)
      return QModelIndex();

  return createIndex(parentItem->row(),0,parentItem);

}
int CoordinateSystemModel::rowCount(const QModelIndex &parent) const 
{
  CoordinateSystemItem *parentItem;
  if(parent.column() > 0)
      return 0;

  if(!parent.isValid())
      parentItem = root_item_;
  else
      parentItem = static_cast<CoordinateSystemItem*>(parent.internalPointer());

  return parentItem->childCount();
}
int	CoordinateSystemModel::columnCount(const QModelIndex & parent) const 
{
  if(parent.isValid())
    return static_cast<CoordinateSystemItem*>(parent.internalPointer())->columnCount();
  else
      return root_item_->columnCount();
}
