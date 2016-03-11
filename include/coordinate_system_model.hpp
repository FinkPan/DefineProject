#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_MODEL_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_MODEL_HPP_

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QIcon>
#include <QMap>
#include <QMultiMap>

// #include "geographic_coordinate_system_item.hpp"
// #include "projected_coordinate_system_item.hpp"

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
  void add_item(const QString& wkt);
  CoordinateSystemItem* gcs_item() const;
  CoordinateSystemItem* pcs_item() const;

  void SetItemExpandedIcon(const QModelIndex &index);
  void SetItemCollapsedIcon(const QModelIndex &index);

private:
  CoordinateSystemItem *root_item_;
  CoordinateSystemItem *gcs_item_;
  CoordinateSystemItem *pcs_item_;
  CoordinateSystemItem *pcs_gauss_kruger_item_;
  QIcon *item_icon_folder_clolse_;
  QIcon *item_icon_folder_open_;
  QIcon *item_icon_coordinate_system_;
  QStringList pcs_projection_;
  QMap<QString, CoordinateSystemItem*> item_map_;
};

#endif
