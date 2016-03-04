#ifndef _DEFINEPROJECT_Projected_COORDINATE_SYSTEM_HPP_
#define _DEFINEPROJECT_Projected_COORDINATE_SYSTEM_HPP_

#include <string>
#include "coordinate_system_data.hpp"

class ProjectedCoordinateSystem : public CoordinateSystemData
{
public:
  ProjectedCoordinateSystem();
  virtual ~ProjectedCoordinateSystem();
  bool operator==(const ProjectedCoordinateSystem& pcs);

  virtual std::string& name();
  virtual int& wkid();
  virtual QString Text();

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
  std::string name_;
  int wkid_;
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
