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

  ui->treeView->header()->hide();
  ui->treeView->setStyleSheet(" \
      QTreeView::branch:has-siblings:!adjoins-item {\
            border-image: url(:/vline) 0;\
    }\
    QTreeView::branch:has-siblings:adjoins-item {\
         border-image: url(:/branch_more) 0;\
    }\
    QTreeView::branch:!has-children:!has-siblings:adjoins-item {\
          border-image: url(:/branch_end) 0;\
    }\
    QTreeView::branch:has-children:!has-siblings:closed,\
    QTreeView::branch:closed:has-children:has-siblings{ \
      border-image: none;                               \
            image: url(:/branch_closed);                    \
    }                                                   \
                                                        \
    QTreeView::branch:open:has-children:!has-siblings,  \
    QTreeView::branch:open:has-children:has-siblings{   \
      border-image: none;                               \
            image: url(:/branch_open);                      \
    }                                                   \
    ");
  coordinate_system_model_ = new CoordinateSystemModel;
  ui->treeView->setModel(coordinate_system_model_);

  connect(ui->treeView,&QTreeView::expanded,
          coordinate_system_model_,&CoordinateSystemModel::setItemExpandedIcon);
  connect(ui->treeView,&QTreeView::collapsed,
          coordinate_system_model_,&CoordinateSystemModel::setItemCollapsedIcon);


 // ReadCoordinateSystem("gcs.csv");
}

MainWindow::~MainWindow()
{
  delete coordinate_system_model_;
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
  CoordinateSystemItem *item = model->getItem(index);
  if (item->IsCoordinatieSystem())
  {
//     ui->textEdit->setText(item->data().toString());
    ui->textEdit->setText(item->gcs().GCS_name_);
  }

}

