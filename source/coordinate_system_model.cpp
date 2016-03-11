#include "coordinate_system_model.hpp"
#include "coordinate_system_item.hpp"
#include "read_write_file.hpp"

#include "gdal_priv.h"
#include "cpl_conv.h"
#include <ogr_spatialref.h>

CoordinateSystemModel::CoordinateSystemModel(QObject *parent)
  : QAbstractItemModel(parent)
{
  root_item_ = new CoordinateSystemItem(
    "root",CoordinateSystemItem::FOLDER_CLOSE);
  item_icon_folder_clolse_     = new QIcon(":/folder_closed");
  item_icon_folder_open_       = new QIcon(":/folder_open");
  item_icon_coordinate_system_ = new QIcon(":/earth");

  gcs_item_ = new CoordinateSystemItem(
    tr("Geographic Coordinate System"),
    CoordinateSystemItem::FOLDER_CLOSE,root_item_);
  pcs_item_ = new CoordinateSystemItem(
    tr("Projected_coordinate_system"),
    CoordinateSystemItem::FOLDER_CLOSE,root_item_);
  pcs_gauss_kruger_item_ = new CoordinateSystemItem(
    tr("Gauss_Kruger"),
    CoordinateSystemItem::FOLDER_CLOSE,pcs_item_);

  ReadWriteFile::ReadCoordinateSystem("coordinate_system.txt",*this);

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
  if (item && (item->item_type() != CoordinateSystemItem::COORDINATE_SYSTEM))
  {
    item->set_item_type(CoordinateSystemItem::FOLDER_OPEN);
  }
}

void CoordinateSystemModel::SetItemCollapsedIcon(const QModelIndex &index)
{
  CoordinateSystemItem *item =
    static_cast<CoordinateSystemItem*>(index.internalPointer());
  if(item && (item->item_type() != CoordinateSystemItem::COORDINATE_SYSTEM))
  {
    item->set_item_type(CoordinateSystemItem::FOLDER_CLOSE);
  }
}

QModelIndex CoordinateSystemModel::index(int row,int column,const QModelIndex &parent) const 
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

CoordinateSystemItem* CoordinateSystemModel::gcs_item() const
{
  return gcs_item_;
}
CoordinateSystemItem* CoordinateSystemModel::pcs_item() const
{
  return pcs_item_;
}

void CoordinateSystemModel::add_item(const QString& wkt)
{
  QByteArray ba_wkt = wkt.toLatin1();
  char *c_wkt = ba_wkt.data();
  OGRSpatialReference oSRS;
  oSRS.importFromWkt(&c_wkt);
  if(oSRS.IsGeographic())
  {
    const char* geogcs_name = oSRS.GetAttrValue("GEOGCS");
    QString t = QString(geogcs_name);
    CoordinateSystemItem* gcs_item =
      new CoordinateSystemItem(wkt,
      CoordinateSystemItem::COORDINATE_SYSTEM,gcs_item_);

  }
  else if(oSRS.IsProjected())
  {
    QString name = QString(oSRS.GetAttrValue("GEOGCS"));
    CoordinateSystemItem* gauss_kruger_item = nullptr;

    if (item_map_.contains(name))
    {
      CoordinateSystemItem* name_item = item_map_[name];
    }
    else
    {
      CoordinateSystemItem* name_item =
        new CoordinateSystemItem(name,
        CoordinateSystemItem::COORDINATE_SYSTEM,pcs_gauss_kruger_item_);
      item_map_.insert(name,name_item);
      CoordinateSystemItem* item =
        new CoordinateSystemItem(wkt,
        CoordinateSystemItem::COORDINATE_SYSTEM,name_item);
    }
  }

}

