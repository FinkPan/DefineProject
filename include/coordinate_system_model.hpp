#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_MODEL_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_MODEL_HPP_

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QIcon>

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
  void addItem(CoordinateSystemItem* item, CoordinateSystemItem *parentItem = 0);

  bool setItemExpandedIcon(const QModelIndex &index);
  bool setItemCollapsedIcon(const QModelIndex &index);

private:
  CoordinateSystemItem *root_item_;

};

#endif
