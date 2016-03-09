#include <fstream>

#include "mainwindow.hpp"
#include "coordinate_system_model.hpp"
#include "coordinate_system_item.hpp"
#include "read_write_file.hpp"

#include "ui_main.h"

#include <QTreeView>
#include <QTextEdit>
#include <QScrollBar>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent):
QWidget(parent),
    ui(new Ui::Widget)
{
  coordinate_system_model_ = new CoordinateSystemModel(this);
  item_selection_model_ = new QItemSelectionModel(coordinate_system_model_);

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

  ui->pushButton_output->setDisabled(true);
  ui->lineEdit_output->setDisabled(true);
  ui->lineEdit_output->setReadOnly(true);
  ui->lineEdit_input->setReadOnly(true);

  ui->checkBox->setChecked(true);

  ui->treeView->setSelectionModel(item_selection_model_);

  connect(ui->treeView,&QTreeView::clicked,
        this,&MainWindow::SetText);
  connect(ui->treeView,&QTreeView::expanded,
        coordinate_system_model_,&CoordinateSystemModel::SetItemExpandedIcon);
  connect(ui->treeView,&QTreeView::collapsed,
          coordinate_system_model_,&CoordinateSystemModel::SetItemCollapsedIcon);
  connect(ui->pushButton_ok,&QPushButton::clicked,
          this,&MainWindow::OnPushButtonOk);
  connect(ui->pushButton_input,&QPushButton::clicked,
          this,&MainWindow::OnPushButtonInput);
  connect(ui->pushButton_output,&QPushButton::clicked,
          this,&MainWindow::OnPushButtonOutput);
  connect(ui->checkBox,&QCheckBox::stateChanged,
          this,&MainWindow::OnCheckBoxReplaceFiles);

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
    ui->textEdit->setText(item->Text());
  }
  else if (item->item_type() == CoordinateSystemItem::PROJECTED_COORDINATE_SYSTEM)
  {
    ui->textEdit->setText(item->Text());
    ProjectedCoordinateSystemItem* pcs =
      dynamic_cast<ProjectedCoordinateSystemItem*>(item);

    int gcs_wkid = pcs->gcs_wkid();

    CoordinateSystemItem* gcs = model->getItem(gcs_wkid);
    if(gcs != nullptr)
    {
      ui->textEdit->append("\nGeographic Coordinate System:");
      ui->textEdit->append(gcs->Text());
    }
    else
    {
      ui->textEdit->append("\nWARNING: can't find Geographic Coordinate System!\n");
    }
  }
  QScrollBar *sb = ui->textEdit->verticalScrollBar();
  sb->setValue(sb->minimum());

}

int MainWindow::OnPushButtonOk()
{
  if (input_files_.isEmpty())
  {
    QMessageBox::warning(this,tr("Waring"),
                              tr("input tif file is empty."),
                               QMessageBox::Ok);
    return -1;
  }

  const QModelIndex index = item_selection_model_->currentIndex();
  const CoordinateSystemModel *model = 
    dynamic_cast<const CoordinateSystemModel *>(index.model());
  CoordinateSystemItem *item = model->getItem(index);

  if (item->item_type() == CoordinateSystemItem::GEOGRAPHIC_COORDINATE_SYSTEM)
  {
    const GeographicCoordinateSystemItem* gcs_item =
      dynamic_cast<const GeographicCoordinateSystemItem*>(item);
    ReadWriteFile::ReNameTiffFiles(input_files_,out_dir_,gcs_item);
  }
  else if (item->item_type() == CoordinateSystemItem::PROJECTED_COORDINATE_SYSTEM)
  {
    const ProjectedCoordinateSystemItem* pcs_item =
      dynamic_cast<const ProjectedCoordinateSystemItem*>(item);
    const GeographicCoordinateSystemItem* gcs_item =
      dynamic_cast<GeographicCoordinateSystemItem*>(
      model->getItem(pcs_item->gcs_wkid()));
    ReadWriteFile::ReNameTiffFiles(input_files_,out_dir_,gcs_item,pcs_item);
  }
  else
  {
    ui->textEdit->setText(item->Text() + tr(" can't write."));
  }

  return 0;
}

int MainWindow::OnPushButtonInput()
{
  input_files_ = QFileDialog::getOpenFileNames(
                        this,
                        "Select one or more files to open",
                        "/home",
                        "Tiff Images (*.tif *.tiff)");  

  QString file;
  for(auto &iter : input_files_)
  {
    file += iter;
    file += " ";
  }

  ui->lineEdit_input->setText(file);

  return 0;
}
int MainWindow::OnPushButtonOutput()
{
  out_dir_ = QFileDialog::getExistingDirectory(
    this,tr("Open Directory"),
     "/home",
    QFileDialog::ShowDirsOnly | 
    QFileDialog::DontResolveSymlinks);

  ui->lineEdit_output->setText(out_dir_);

  return 0;
}

int MainWindow::OnCheckBoxReplaceFiles()
{
  if (ui->checkBox->isChecked())
  {
    ui->pushButton_output->setDisabled(true);
    ui->lineEdit_output->setDisabled(true);
  }
  else
  {
    ui->pushButton_output->setDisabled(false);
    ui->lineEdit_output->setDisabled(false);
  }

  return 0;
}

