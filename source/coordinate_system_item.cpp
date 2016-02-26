#include <QStringList>

#include "coordinate_system_item.hpp"

CoordinateSystemItem::CoordinateSystemItem(
  const QVariant &data, CoordinateSystemItem *parent,bool is_coordinatie_system)
  : is_coordinatie_system_(is_coordinatie_system)
{
    m_parentItem = parent;
    m_itemData = data;
    if (is_coordinatie_system)
      icon_ = new QIcon(":/earth");
    else
      icon_ = new QIcon(":/folder_closed");

    if (parent != nullptr)
    {
      parent->appendChild(this);
    }

}

CoordinateSystemItem::~CoordinateSystemItem()
{
  delete icon_;
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

bool CoordinateSystemItem::IsCoordinatieSystem()
{
  return is_coordinatie_system_;
}

bool CoordinateSystemItem::setIcon(QIcon *icon)
{
  if (is_coordinatie_system_)
    return false;
  
  icon_->swap(*icon);
  return true;
}

QVariant CoordinateSystemItem::getIcon() const
{
  return *icon_;
}


