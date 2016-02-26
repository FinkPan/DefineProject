#include "coordinate_system_model.hpp"
#include "coordinate_system_item.hpp"

CoordinateSystemModel::CoordinateSystemModel(QObject *parent)
  : QAbstractItemModel(parent)
{
  root_item_ = new CoordinateSystemItem("root");
  CoordinateSystemItem *test1 = new CoordinateSystemItem(tr("Geographic Coordinate Systems"),root_item_,false);
  CoordinateSystemItem *test2 = new CoordinateSystemItem(tr("Projected Coordinate Systems"),root_item_,false);
  CoordinateSystemItem *test3 = new CoordinateSystemItem("Asia",test1,false);
  CoordinateSystemItem *test4 = new CoordinateSystemItem("Beijing 1954",test3);
  CoordinateSystemItem *test5 = new CoordinateSystemItem("China_Geodetic_Coordinate_System_2000",test3);
  CoordinateSystemItem *test6 = new CoordinateSystemItem("Gauss_Kruger",test2,false);
  CoordinateSystemItem *test7 = new CoordinateSystemItem("Beijing 1954",test6,false);
  CoordinateSystemItem *test8 = new CoordinateSystemItem("CGCS2000",test6,false);
  CoordinateSystemItem *test9 = new CoordinateSystemItem("Beijing_1954_3_Degree_GK_CM_105E",test7);
  CoordinateSystemItem *test10 = new CoordinateSystemItem("Beijing_1954_3_Degree_GK_CM_108E",test7);
  CoordinateSystemItem *test11 = new CoordinateSystemItem("Beijing_1954_3_Degree_GK_CM_111E",test7);
  CoordinateSystemItem *test12 = new CoordinateSystemItem("Beijing_1954_3_Degree_GK_CM_114E",test7);
  CoordinateSystemItem *test13 = new CoordinateSystemItem("CGCS2000_3_Degree_GK_CM_105E",test8);
  CoordinateSystemItem *test14 = new CoordinateSystemItem("CGCS2000_3_Degree_GK_CM_108E",test8);
  CoordinateSystemItem *test15 = new CoordinateSystemItem("CGCS2000_3_Degree_GK_CM_111E",test8);
  CoordinateSystemItem *test16 = new CoordinateSystemItem("CGCS2000_3_Degree_GK_CM_114E",test8);

  GCS &g1 = test4->gcs();
  g1.GCS_name_ = "GCS_Beijing_1954";
  g1.datum_name_ = "D_Beijing_1954";

}

CoordinateSystemModel::~CoordinateSystemModel()
{
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

    CoordinateSystemModel *model = (CoordinateSystemModel *)index.model();
    if (model == nullptr)
    {
      return QVariant();
    }

    CoordinateSystemItem *item = model->getItem(index);
    return item->getIcon();
  }

  if(role != Qt::DisplayRole)
      return QVariant();
  CoordinateSystemItem *item =
    static_cast<CoordinateSystemItem*>(index.internalPointer());
  return item->data();

}

bool CoordinateSystemModel::setItemExpandedIcon(const QModelIndex &index)
{
  CoordinateSystemModel *model = (CoordinateSystemModel *)index.model();
  if(model == nullptr)
  {
    return false;
  }
  CoordinateSystemItem *item = model->getItem(index);
  item->setIcon(new QIcon(":/folder_open"));

}

bool CoordinateSystemModel::setItemCollapsedIcon(const QModelIndex &index)
{
  CoordinateSystemModel *model = (CoordinateSystemModel *)index.model();
  if(model == nullptr)
  {
    return false;
  }
  CoordinateSystemItem *item = model->getItem(index);
  item->setIcon(new QIcon(":/folder_closed"));

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

CoordinateSystemItem* CoordinateSystemModel::getItem(const QModelIndex &index) const
{
  return static_cast<CoordinateSystemItem*>(index.internalPointer());
}

void CoordinateSystemModel::addItem(
  CoordinateSystemItem* item,
  CoordinateSystemItem *parentItem)
{

}
