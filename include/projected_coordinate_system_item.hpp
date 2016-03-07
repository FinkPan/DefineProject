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
  std::string& projection();
  double& false_easting();
  double& false_northing();
  double& central_meridian();
  double& scale_factor();
  double& latitude_of_origin();
  std::string& linear_unit_name();
  double& linear_unit();

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
