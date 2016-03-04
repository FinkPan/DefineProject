#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_

#include <QList>
#include <QVariant>
#include <QIcon>

//#include "geographic_coordinate_system.hpp"
//#include "projected_coordinate_system.hpp"
#include "coordinate_system_data.hpp"

class CoordinateSystemItem
{
public:
  enum ItemType
  {
    FOLDER_CLOSE,
    FOLDER_OPEN,
    GEOGRAPHIC_COORDINATE_SYSTEM,
    PROJECTED_COORDINATE_SYSTEM,
  };

  explicit CoordinateSystemItem(
    QVariant item_name,
    ItemType item_type,
    CoordinateSystemItem *parent_item = nullptr);
  ~CoordinateSystemItem();

  CoordinateSystemItem *child(int row);

  bool set_item_name(QVariant item_name);
  void set_item_type(ItemType item_type);
  void set_item_data(CoordinateSystemData* data);

  int childCount() const;
  int columnCount() const;
  int row() const;
  QVariant item_name() const;
  ItemType item_type() const;
  int item_wkid() const;
  CoordinateSystemItem* parent_item() const;
  CoordinateSystemItem* child_item(int i) const;

  CoordinateSystemData* data() const;

private:
  QVariant item_name_;
  ItemType item_type_;

  QList<CoordinateSystemItem*> child_items_;
  CoordinateSystemItem *parent_item_;

  CoordinateSystemData* data_;

};

#endif
