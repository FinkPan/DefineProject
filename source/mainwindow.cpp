#include <fstream>

#include "mainwindow.hpp"
#include "coordinate_system_model.hpp"
#include "coordinate_system_item.hpp"

#include "ui_main.h"

#include <QTreeView>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent):
QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->treeView,&QTreeView::clicked,
          this,&MainWindow::SetText);

  CoordinateSystemModel *coordinate_system_model = new CoordinateSystemModel;

  ui->treeView->header()->hide();
  ui->treeView->setModel(coordinate_system_model);

 // ReadCoordinateSystem("gcs.csv");
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::ReadCoordinateSystem(const std::string& file_path)
{
 std::ifstream in_file(file_path);
 if (in_file.is_open())
 {
   std::string str_line;
   getline(in_file,str_line);
   while(getline(in_file,str_line));
   {
     std::string str_line1 = str_line;
   }
 }
}

void MainWindow::SetText(const QModelIndex &index)
{
  CoordinateSystemModel *model = ( CoordinateSystemModel *)index.model();

//   QVariant item = model->data(index,Qt::DisplayRole);

  CoordinateSystemItem *item = model->getItem(index);
  if (item->IsCoordinatieSystem())
  {
    ui->textEdit->setText(item->data().toString());
  }
  


}

