#include <iostream>

#include "projected_coordinate_system_item.hpp"

ProjectedCoordinateSystemItem::ProjectedCoordinateSystemItem(
  QVariant item_name,
  ItemType item_type,
  CoordinateSystemItem *parent_item)
  : GeographicCoordinateSystemItem(item_name,item_type,parent_item)
  , gcs_wkid_(0)
  , projection_("")
  , false_easting_(0.0)
  , false_northing_(0.0)
  , central_meridian_(0.0)
  , scale_factor_(0.0)
  , latitude_of_origin_(0.0)
  , linear_unit_name_("")
  , linear_unit_(0)
{
}

ProjectedCoordinateSystemItem::~ProjectedCoordinateSystemItem()
{
}

int& ProjectedCoordinateSystemItem::gcs_wkid()
{
  return gcs_wkid_;
}
const int& ProjectedCoordinateSystemItem::gcs_wkid() const
{
  return gcs_wkid_;
}
std::string& ProjectedCoordinateSystemItem::projection()
{
  return projection_;
}
const std::string& ProjectedCoordinateSystemItem::projection() const
{
  return projection_;
}
double& ProjectedCoordinateSystemItem::false_easting()
{
  return false_easting_;
}
const double& ProjectedCoordinateSystemItem::false_easting() const
{
  return false_easting_;
}
double& ProjectedCoordinateSystemItem::false_northing()
{
  return false_northing_;
}
const double& ProjectedCoordinateSystemItem::false_northing() const
{
  return false_northing_;
}
double& ProjectedCoordinateSystemItem::central_meridian()
{
  return central_meridian_;
}
const double& ProjectedCoordinateSystemItem::central_meridian() const
{
  return central_meridian_;
}
double& ProjectedCoordinateSystemItem::scale_factor()
{
  return scale_factor_;
}
const double& ProjectedCoordinateSystemItem::scale_factor() const
{
  return scale_factor_;
}
double& ProjectedCoordinateSystemItem::latitude_of_origin()
{
  return latitude_of_origin_;
}
const double& ProjectedCoordinateSystemItem::latitude_of_origin() const
{
  return latitude_of_origin_;
}
std::string& ProjectedCoordinateSystemItem::linear_unit_name()
{
  return linear_unit_name_;
}
const std::string& ProjectedCoordinateSystemItem::linear_unit_name() const
{
  return linear_unit_name_;
}
double& ProjectedCoordinateSystemItem::linear_unit()
{
  return linear_unit_;
}
const double& ProjectedCoordinateSystemItem::linear_unit() const
{
  return linear_unit_;
}

QString ProjectedCoordinateSystemItem::Text()
{
  return QString(
"%1\n\
WKID: %2\n\n\
Projection: %3\n\
False Easting: %4\n\
False Northing: %5\n\
Central Meridian: %6\n\
Scale Factor: %7\n\
Latitude Of Origin: %8\n\
Linear Unit: %9 (%10)"
)
.arg(item_name_.toString())
.arg(wkid_)
.arg(QString::fromStdString(projection_))
.arg(false_easting_)
.arg(false_northing_)
.arg(central_meridian_)
.arg(scale_factor_)
.arg(latitude_of_origin_)
.arg(QString::fromStdString(linear_unit_name_)).arg(linear_unit_) + "\n\n" +
GeographicCoordinateSystemItem::Text();

}