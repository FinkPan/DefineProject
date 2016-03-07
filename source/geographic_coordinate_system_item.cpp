#include <iostream>

#include "geographic_coordinate_system_item.hpp"

GeographicCoordinateSystemItem::GeographicCoordinateSystemItem(
      QVariant item_name,
    ItemType item_type,
    CoordinateSystemItem *parent_item)
  : CoordinateSystemItem(item_name,item_type,parent_item)
  , angular_unit_("")
  , radians_per_unit_(0.0)
  , prime_meridian_("")
  , prime_meridian_offset_(0.0)
  , datum_("")
  , spheroid_("")
  , semimajor_axis_(0.0)
  , inverse_flattening_(0.0)
{
}

GeographicCoordinateSystemItem::~GeographicCoordinateSystemItem()
{
}

std::string& GeographicCoordinateSystemItem::angular_unit()
{
  return angular_unit_;
}
double& GeographicCoordinateSystemItem::radians_per_unit()
{
  return radians_per_unit_;
}

std::string& GeographicCoordinateSystemItem::prime_meridian()
{
  return prime_meridian_;
}
double& GeographicCoordinateSystemItem::prime_meridian_offset()
{
  return prime_meridian_offset_;
}

std::string& GeographicCoordinateSystemItem::datum()
{
  return datum_;
}

std::string& GeographicCoordinateSystemItem::spheroid()
{
  return spheroid_;
}
double& GeographicCoordinateSystemItem::semimajor_axis()
{
  return semimajor_axis_;
}
double& GeographicCoordinateSystemItem::inverse_flattening()
{
  return inverse_flattening_;
}

QString GeographicCoordinateSystemItem::Text()
{
  return QString(
"%1\n\
WKID: %2\n\n\
Angular Unit: %3 (%4)\n\
Prime Meridian: %5 (%6)\n\
Datum: %7\n\
  Spheroid: %8\n\
  Semimajor Axis: %9\n\
  Inverse Flattening: %10\n\
")
.arg(item_name_.toString())
.arg(wkid_)
.arg(QString::fromStdString(angular_unit_)).arg(radians_per_unit_)
.arg(QString::fromStdString(prime_meridian_)).arg(prime_meridian_offset_)
.arg(QString::fromStdString(datum_))
.arg(QString::fromStdString(spheroid_))
.arg(semimajor_axis_)
.arg(inverse_flattening_);

}