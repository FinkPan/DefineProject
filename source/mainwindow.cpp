#include <fstream>

#include "mainwindow.hpp"
#include "coordinate_system_model.hpp"
#include "coordinate_system_item.hpp"

#include "ui_main.h"

#include <QTreeView>
#include <QTextEdit>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent):
QWidget(parent),
    ui(new Ui::Widget)
{
  coordinate_system_model_ = new CoordinateSystemModel;

  ui->setupUi(this);
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
  ui->treeView->setModel(coordinate_system_model_);
  ui->textEdit->setReadOnly(true);
  ui->textEdit->setWordWrapMode(QTextOption::NoWrap);

  connect(ui->treeView,&QTreeView::clicked,
        this,&MainWindow::SetText);
  connect(ui->treeView,&QTreeView::expanded,
        coordinate_system_model_,&CoordinateSystemModel::SetItemExpandedIcon);
  connect(ui->treeView,&QTreeView::collapsed,
          coordinate_system_model_,&CoordinateSystemModel::SetItemCollapsedIcon);
  connect(ui->pushButton_ok,&QPushButton::clicked,
          this,&MainWindow::WriteData);

}

MainWindow::~MainWindow()
{
  delete coordinate_system_model_;
  delete ui;
}

void MainWindow::SetText(const QModelIndex &index)
{
  CoordinateSystemModel *model = ( CoordinateSystemModel *)index.model();
  CoordinateSystemItem *item = model->getItem(index);

  if(item->item_type() == CoordinateSystemItem::GEOGRAPHIC_COORDINATE_SYSTEM)
  {
    ui->textEdit->setText(item->data()->Text());
  }
  else if (item->item_type() == CoordinateSystemItem::PROJECTED_COORDINATE_SYSTEM)
  {
    ui->textEdit->setText(item->data()->Text());
    ProjectedCoordinateSystem* pcs = 
      dynamic_cast<ProjectedCoordinateSystem*>(item->data());

    int gcs_wkid = pcs->gcs_wkid();

    CoordinateSystemItem* gcs = model->getItem(gcs_wkid);
    if(gcs != nullptr)
    {
      ui->textEdit->append("\nGeographic Coordinate System:");
      ui->textEdit->append(gcs->data()->Text());
    }
    else
    {
      ui->textEdit->append("\nWARNING: can't find Geographic Coordinate System!\n");
    }
  }
  QScrollBar *sb = ui->textEdit->verticalScrollBar();
  sb->setValue(sb->minimum());

}

void MainWindow::WriteData()
{

}

