#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_

#include <QList>
#include <QVariant>

class CoordinateSystemItem
{
public:
  enum ItemType
  {
    FOLDER,
    VALUE
  };

  explicit CoordinateSystemItem(
    const QVariant &data,CoordinateSystemItem *parentItem = 0);
  ~CoordinateSystemItem();

  void appendChild(CoordinateSystemItem *child);

  CoordinateSystemItem *child(int row);
  int childCount() const;
  int columnCount() const;
  QVariant data() const;
  int row() const;
  CoordinateSystemItem *parentItem();
  void setCoordinatieSystem();
  bool IsCoordinatieSystem();

private:
  QList<CoordinateSystemItem*> m_childItems;
  QVariant m_itemData;
  CoordinateSystemItem *m_parentItem;
  bool is_coordinatie_system_;
};

#endif
