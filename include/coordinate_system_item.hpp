#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_

#include <QList>
#include <QVariant>

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
  virtual ~CoordinateSystemItem();

  virtual QString Text();

  int& wkid();

  bool set_item_name(QVariant item_name);
  void set_item_type(ItemType item_type);

  int childCount() const;
  int columnCount() const;
  int row() const;
  QVariant item_name() const;
  ItemType item_type() const;
  
  CoordinateSystemItem* parent_item() const;
  CoordinateSystemItem* child_item(int i) const;
  void add_child_item(CoordinateSystemItem* item);

  CoordinateSystemItem *child(int row);


protected:
  int wkid_;
  QVariant item_name_;

private:
  ItemType item_type_;
  CoordinateSystemItem *parent_item_;
  QList<CoordinateSystemItem*> child_items_;

};

#endif
