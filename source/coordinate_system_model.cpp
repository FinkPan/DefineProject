#include "coordinate_system_model.hpp"
#include "coordinate_system_item.hpp"
#include "read_write_file.hpp"

CoordinateSystemModel::CoordinateSystemModel(QObject *parent)
  : QAbstractItemModel(parent)
{
  root_item_ = new CoordinateSystemItem(
    "root",CoordinateSystemItem::FOLDER_CLOSE);
  item_icon_folder_clolse_     = new QIcon(":/folder_closed");
  item_icon_folder_open_       = new QIcon(":/folder_open");
  item_icon_coordinate_system_ = new QIcon(":/earth");

  ReadWriteFile::ReadCoordinateSystem("coordinate_system.xml",*root_item_);

}

CoordinateSystemModel::~CoordinateSystemModel()
{
  delete item_icon_folder_clolse_;
  delete item_icon_folder_open_;
  delete item_icon_coordinate_system_;
  delete root_item_;
}

QVariant CoordinateSystemModel::data(const QModelIndex &index,int role) const
{

  if(!index.isValid())
  return QVariant();

  if(role == Qt::DecorationRole //&&
     //index.column()==0  &&    //第一列的节点  
     //rowCount(index)==0      //子节点数为0  
    )
  {
    CoordinateSystemItem *item = static_cast<CoordinateSystemItem*>(index.internalPointer());
    CoordinateSystemItem::ItemType item_icon_type = item->item_type();

    switch(item_icon_type)
    {
    case CoordinateSystemItem::FOLDER_CLOSE:
      return *item_icon_folder_clolse_;
    case CoordinateSystemItem::FOLDER_OPEN:
      return *item_icon_folder_open_;
    default:
      return*item_icon_coordinate_system_;;
    }
  }

  if(role == Qt::DisplayRole)
  {
    CoordinateSystemItem *item = 
      static_cast<CoordinateSystemItem*>(index.internalPointer());
  return item->item_name();
  }

  return QVariant();

}

void CoordinateSystemModel::SetItemExpandedIcon(const QModelIndex &index)
{
  CoordinateSystemItem *item =
    static_cast<CoordinateSystemItem*>(index.internalPointer());
  if (item && (item->item_type() != CoordinateSystemItem::GEOGRAPHIC_COORDINATE_SYSTEM ||
    item->item_type() != CoordinateSystemItem::PROJECTED_COORDINATE_SYSTEM))
  {
    item->set_item_type(CoordinateSystemItem::FOLDER_OPEN);
  }
}

void CoordinateSystemModel::SetItemCollapsedIcon(const QModelIndex &index)
{
  CoordinateSystemItem *item =
    static_cast<CoordinateSystemItem*>(index.internalPointer());
  if(item && (item->item_type() != CoordinateSystemItem::GEOGRAPHIC_COORDINATE_SYSTEM ||
    item->item_type() != CoordinateSystemItem::PROJECTED_COORDINATE_SYSTEM))
  {
    item->set_item_type(CoordinateSystemItem::FOLDER_CLOSE);
  }
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

  return QModelIndex();
}
QModelIndex CoordinateSystemModel::parent(const QModelIndex &index) const 
{
  if(!index.isValid())
    return QModelIndex();

  CoordinateSystemItem *childItem = 
    static_cast<CoordinateSystemItem*>(index.internalPointer());
  CoordinateSystemItem *parentItem = childItem->parent_item();

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

CoordinateSystemItem* CoordinateSystemModel::getItem(const QModelIndex &index) const
{
  return static_cast<CoordinateSystemItem*>(index.internalPointer());
}

CoordinateSystemItem* CoordinateSystemModel::getItem(int wkid) const
{
  return TraverseItems(wkid,root_item_);
}

void CoordinateSystemModel::AddItems(
  CoordinateSystemItem* item,
  CoordinateSystemItem *parentItem)
{

}

CoordinateSystemItem* CoordinateSystemModel::TraverseItems(
  int wkid, CoordinateSystemItem* parent_item) const
{
  CoordinateSystemItem* item;
  for(int i = 0; i < parent_item->childCount(); ++i)
  {
    item = parent_item->child_item(i);
    if(item->wkid() == wkid)
    {
      return item;
    }
    //return TraverseItems(wkid,item);
    CoordinateSystemItem* item1 = TraverseItems(wkid,item);
    if (item1 != nullptr)
    {
      return item1;
    }
  }
  return nullptr;
}
