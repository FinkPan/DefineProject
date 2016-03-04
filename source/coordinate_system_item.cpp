#include "coordinate_system_item.hpp"

CoordinateSystemItem::CoordinateSystemItem(
  QVariant item_name,
  ItemType item_type,
  CoordinateSystemItem *parent_item)
  : parent_item_(parent_item)
  , item_name_(item_name)
  , item_type_(item_type)
  , data_(nullptr)
{
    if (parent_item_ != nullptr)
      parent_item_->child_items_.append(this);
}

CoordinateSystemItem::~CoordinateSystemItem()
{  
  if (data_ != nullptr)
  {
    delete data_;
  }
  
  qDeleteAll(child_items_);
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
  if (item_name_.isNull())
    return 0;
  else
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

QVariant CoordinateSystemItem::item_name() const
{
  return item_name_;
}

void CoordinateSystemItem::set_item_type(ItemType item_type)
{
  item_type_ = item_type;
}

void CoordinateSystemItem::set_item_data(CoordinateSystemData* data)
{
  data_ = data;
}

CoordinateSystemItem::ItemType CoordinateSystemItem::item_type() const
{
  return item_type_;
}

CoordinateSystemData* CoordinateSystemItem::data() const
{
  return data_;
}

int CoordinateSystemItem::item_wkid() const
{
  switch(item_type_)
  {
  case GEOGRAPHIC_COORDINATE_SYSTEM:
  case PROJECTED_COORDINATE_SYSTEM:
    return data_->wkid();
  default:
    return -1;
  }
}

