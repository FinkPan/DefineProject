#include <iostream>

#include "coordinate_system_item.hpp"

CoordinateSystemItem::CoordinateSystemItem(
  const QString& wkt,
  ItemType item_type,
  CoordinateSystemItem *parent_item)
  : item_type_(item_type)
  , parent_item_(parent_item)
{
  QByteArray ba_wkt = wkt.toLatin1();
  char *c_wkt = ba_wkt.data();
  oSRS_.importFromWkt(&c_wkt);
  if(parent_item_ != nullptr)
    parent_item_->add_child_item(this);
}

CoordinateSystemItem::~CoordinateSystemItem()
{  
  qDeleteAll(child_items_);
}

void CoordinateSystemItem::add_child_item(CoordinateSystemItem* item)
{
  child_items_.append(item);
}

CoordinateSystemItem *CoordinateSystemItem::child(int row)
{
    return child_items_.value(row);
}

int CoordinateSystemItem::childCount() const
{
    return child_items_.count();
}

int CoordinateSystemItem::columnCount() const
{
//   if (item_name_.isNull())
//     return 0;
//   else
    return 1;
}

CoordinateSystemItem *CoordinateSystemItem::parent_item() const
{
    return parent_item_;
}

int CoordinateSystemItem::row() const
{
    if (parent_item_)
        return parent_item_->child_items_.indexOf(
          const_cast<CoordinateSystemItem*>(this));

    return 0;
}

CoordinateSystemItem* CoordinateSystemItem::child_item(int i) const
{
  int num_item = childCount();
  if (i <= num_item)
  {
    return child_items_[i];
  }
  return nullptr;
}


void CoordinateSystemItem::set_item_type(ItemType item_type)
{
  item_type_ = item_type;
}

QVariant CoordinateSystemItem::item_name() const
{
  if(oSRS_.IsGeographic())
  {
    return QVariant(QString(oSRS_.GetAttrValue("GEOGCS")));
  }
  else if (oSRS_.IsProjected())
  {
    return QVariant(QString(oSRS_.GetAttrValue("PROJCS")));
  }
  return QVariant();
}

CoordinateSystemItem::ItemType CoordinateSystemItem::item_type() const
{
  return item_type_;
}

QString CoordinateSystemItem::Text()
{
//   return item_name_.toString();
  return QString();
  
}

