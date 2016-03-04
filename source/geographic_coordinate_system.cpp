#include "geographic_coordinate_system.hpp"

GeographicCoordinateSystem::GeographicCoordinateSystem()
  : name_("")
  , wkid_(0)
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

GeographicCoordinateSystem::~GeographicCoordinateSystem()
{
}


bool GeographicCoordinateSystem::operator==(
  const GeographicCoordinateSystem& gcs)
{
  return this->wkid_ == gcs.wkid_;
}

std::string& GeographicCoordinateSystem::name()
{
  return name_;
}

int& GeographicCoordinateSystem::wkid()
{
  return wkid_;
}

std::string& GeographicCoordinateSystem::angular_unit()
{
  return angular_unit_;
}
double& GeographicCoordinateSystem::radians_per_unit()
{
  return radians_per_unit_;
}

std::string& GeographicCoordinateSystem::prime_meridian()
{
  return prime_meridian_;
}
double& GeographicCoordinateSystem::prime_meridian_offset()
{
  return prime_meridian_offset_;
}

std::string& GeographicCoordinateSystem::datum()
{
  return datum_;
}

std::string& GeographicCoordinateSystem::spheroid()
{
  return spheroid_;
}
double& GeographicCoordinateSystem::semimajor_axis()
{
  return semimajor_axis_;
}
double& GeographicCoordinateSystem::inverse_flattening()
{
  return inverse_flattening_;
}

QString GeographicCoordinateSystem::Text()
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
.arg(QString::fromStdString(name_))
.arg(wkid_)
.arg(QString::fromStdString(angular_unit_)).arg(radians_per_unit_)
.arg(QString::fromStdString(prime_meridian_)).arg(prime_meridian_offset_)
.arg(QString::fromStdString(datum_))
.arg(QString::fromStdString(spheroid_))
.arg(semimajor_axis_)
.arg(inverse_flattening_);

}