#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_ITEM_HPP_

#include <QList>
#include <QVariant>
#include <QIcon>

#include "geographic_coordinate_system.hpp"

class CoordinateSystemItem
{
public:
  enum ItemType
  {
    FOLDER,
    VALUE
  };

  explicit CoordinateSystemItem(
    const QVariant &data,CoordinateSystemItem *parentItem = nullptr, bool is_coordinatie_system = true);
  ~CoordinateSystemItem();

  void appendChild(CoordinateSystemItem *child);

  CoordinateSystemItem *child(int row);
  int childCount() const;
  int columnCount() const;
  QVariant data() const;
  int row() const;
  CoordinateSystemItem *parentItem();
  bool IsCoordinatieSystem();
  bool setIcon(QIcon *icon);
  QVariant getIcon() const; 

  GCS& gcs(){return gcs_;}

private:
  QList<CoordinateSystemItem*> m_childItems;
  QVariant m_itemData;
  CoordinateSystemItem *m_parentItem;
  bool is_coordinatie_system_;
  QIcon *icon_;
  GCS gcs_;


};

#endif
