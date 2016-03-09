#ifndef _DEFINEPROJECT_Projected_COORDINATE_SYSTEM_ITEM_HPP_
#define _DEFINEPROJECT_Projected_COORDINATE_SYSTEM_ITEM_HPP_

#include <string>
#include "coordinate_system_item.hpp"

class ProjectedCoordinateSystemItem : public CoordinateSystemItem
{
public:
  explicit ProjectedCoordinateSystemItem(
  QVariant item_name,
  ItemType item_type,
  CoordinateSystemItem *parent_item = nullptr);
  ~ProjectedCoordinateSystemItem();

  QString Text();

  int& gcs_wkid();
  const int& gcs_wkid() const;
  std::string& projection();
  const std::string& projection() const;
  double& false_easting();
  const double& false_easting() const;
  double& false_northing();
  const double& false_northing() const;
  double& central_meridian();
  const double& central_meridian() const;
  double& scale_factor();
  const double& scale_factor() const;
  double& latitude_of_origin();
  const double& latitude_of_origin() const;
  std::string& linear_unit_name();
  const std::string& linear_unit_name() const;
  double& linear_unit();
  const double& linear_unit() const;

private:
  int gcs_wkid_;
  std::string projection_;
  double false_easting_;
  double false_northing_;
  double central_meridian_;
  double scale_factor_;
  double latitude_of_origin_;
  std::string linear_unit_name_;
  double linear_unit_;

};



#endif
