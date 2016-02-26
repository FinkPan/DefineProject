#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <QMainWindow>

class CoordinateSystemModel;

namespace Ui
{
class MainWindow;
}

class MainWindow: public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void SetText(const QModelIndex &index);

  void ReadCoordinateSystem(const std::string& file_path);

private:
  Ui::MainWindow *ui;
  CoordinateSystemModel *coordinate_system_model_;

};

#endif // MAINWINDOW_H


