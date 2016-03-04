#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_MODEL_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_MODEL_HPP_

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QIcon>
#include <QMap>

#include "geographic_coordinate_system.hpp"
#include "projected_coordinate_system.hpp"

class CoordinateSystemItem;

class CoordinateSystemModel : public QAbstractItemModel
{
  Q_OBJECT
public:
  explicit CoordinateSystemModel(QObject *parent = 0);
  ~CoordinateSystemModel();

  QVariant data(const QModelIndex &index,int role) const Q_DECL_OVERRIDE;

  QModelIndex index(int row,int column,
                    const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
  int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int	columnCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

  CoordinateSystemItem* getItem(const QModelIndex &index) const;
  CoordinateSystemItem* getItem(int wkid) const;

  void SetItemExpandedIcon(const QModelIndex &index);
  void SetItemCollapsedIcon(const QModelIndex &index);

private:
  void AddItems(CoordinateSystemItem* item,CoordinateSystemItem *parentItem = 0);
  CoordinateSystemItem* TraverseItems(int wkid, CoordinateSystemItem* parent_item) const;

private:
  CoordinateSystemItem *root_item_;
  QIcon *item_icon_folder_clolse_;
  QIcon *item_icon_folder_open_;
  QIcon *item_icon_coordinate_system_;
  QMap<int, QModelIndex> wkid_index_;
};

#endif
