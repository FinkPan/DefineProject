#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <QWidget>
#include <QItemSelectionModel>

class CoordinateSystemModel;

namespace Ui
{
class Widget;
}

class MainWindow: public QWidget
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void SetText(const QModelIndex &index);
  int OnPushButtonOk();
  int OnPushButtonInput();
  int OnPushButtonOutput();
  int OnCheckBoxReplaceFiles();

private:
  Ui::Widget *ui;
  CoordinateSystemModel *coordinate_system_model_;
  QItemSelectionModel* item_selection_model_;
  QStringList input_files_;
  QString out_dir_;

};

#endif // MAINWINDOW_H


