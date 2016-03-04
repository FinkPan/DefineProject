#include "projected_coordinate_system.hpp"

ProjectedCoordinateSystem::ProjectedCoordinateSystem()
  : wkid_(0)
  , gcs_wkid_(0)
  , projection_("")
  , false_easting_(0.0)
  , false_northing_(0.0)
  , central_meridian_(0.0)
  , scale_factor_(0.0)
  , latitude_of_origin_(0.0)
  , linear_unit_name_("")
  , linear_unit_(0)
{}

ProjectedCoordinateSystem::~ProjectedCoordinateSystem()
{
}

bool ProjectedCoordinateSystem::operator==(
  const ProjectedCoordinateSystem& pcs)
{
  return (this->wkid_ == pcs.wkid_) && (this->gcs_wkid_ == pcs.gcs_wkid_);
}

std::string& ProjectedCoordinateSystem::name()
{
  return name_;
}
int& ProjectedCoordinateSystem::wkid()
{
  return wkid_;
}

int& ProjectedCoordinateSystem::gcs_wkid()
{
  return gcs_wkid_;
}
std::string& ProjectedCoordinateSystem::projection()
{
  return projection_;
}
double& ProjectedCoordinateSystem::false_easting()
{
  return false_easting_;
}
double& ProjectedCoordinateSystem::false_northing()
{
  return false_northing_;
}
double& ProjectedCoordinateSystem::central_meridian()
{
  return central_meridian_;
}
double& ProjectedCoordinateSystem::scale_factor()
{
  return scale_factor_;
}
double& ProjectedCoordinateSystem::latitude_of_origin()
{
  return latitude_of_origin_;
}
std::string& ProjectedCoordinateSystem::linear_unit_name()
{
  return linear_unit_name_;
}
double& ProjectedCoordinateSystem::linear_unit()
{
  return linear_unit_;
}

QString ProjectedCoordinateSystem::Text()
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
.arg(QString::fromStdString(name_))
.arg(wkid_)
.arg(QString::fromStdString(projection_))
.arg(false_easting_)
.arg(false_northing_)
.arg(central_meridian_)
.arg(scale_factor_)
.arg(latitude_of_origin_)
.arg(QString::fromStdString(linear_unit_name_)).arg(linear_unit_);

}