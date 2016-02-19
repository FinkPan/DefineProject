#include <QStringList>

#include "coordinate_system_item.hpp"

CoordinateSystemItem::CoordinateSystemItem(
  const QVariant &data, CoordinateSystemItem *parent)
  : is_coordinatie_system_(false)
{
    m_parentItem = parent;
    m_itemData = data;
}

CoordinateSystemItem::~CoordinateSystemItem()
{
    qDeleteAll(m_childItems);
}

void CoordinateSystemItem::appendChild(CoordinateSystemItem *item)
{
    m_childItems.append(item);
}

CoordinateSystemItem *CoordinateSystemItem::child(int row)
{
    return m_childItems.value(row);
}

int CoordinateSystemItem::childCount() const
{
    return m_childItems.count();
}

int CoordinateSystemItem::columnCount() const
{
  if (m_itemData.isNull())
    return 0;
  else
    return 1;
}

QVariant CoordinateSystemItem::data() const
{
    return m_itemData;
}

CoordinateSystemItem *CoordinateSystemItem::parentItem()
{
    return m_parentItem;
}

int CoordinateSystemItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(
          const_cast<CoordinateSystemItem*>(this));

    return 0;
}

void CoordinateSystemItem::setCoordinatieSystem()
{
  is_coordinatie_system_ = true;
}

bool CoordinateSystemItem::IsCoordinatieSystem()
{
  return is_coordinatie_system_;
}

