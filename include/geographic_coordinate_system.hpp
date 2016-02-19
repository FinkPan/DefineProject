#ifndef _GEOGRAPHIC_COORDINATE_SYSTEM_HPP_
#define _GEOGRAPHIC_COORDINATE_SYSTEM_HPP_

#include <string>
#include <QVariant>

class GCS
{
public:
  std::string GCS_name_;
  unsigned int GCS_WKID_;
  std::string datum_name_;
  unsigned int datum_WKID_;
  std::string angular_unit_;
  unsigned int angular_unit_WKID_;
  double radians_per_unit_;
  std::string prime_meridian_name_;
  unsigned int prime_meridian_WKID_;
  std::string spheroid_name_;
};


#endif