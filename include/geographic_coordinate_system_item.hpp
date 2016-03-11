#ifndef _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_ITEM_HPP_
#define _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_ITEM_HPP_

#include <string>
#include <QString>
#include "coordinate_system_item.hpp"

class GeographicCoordinateSystemItem : public CoordinateSystemItem
{
public:
  explicit GeographicCoordinateSystemItem(
    const QString& wkt,
    ItemType item_type,
    CoordinateSystemItem *parent_item = nullptr);
  ~GeographicCoordinateSystemItem();

  virtual QString Text();

  std::string& angular_unit();
  const std::string& angular_unit() const;

  double& radians_per_unit();
  const double& radians_per_unit() const;

  std::string& prime_meridian();
  const std::string& prime_meridian() const;
  double& prime_meridian_offset();
  const double& prime_meridian_offset() const;

  std::string& datum();
  const std::string& datum() const;

  std::string& spheroid();
  const std::string& spheroid() const;
  double& semimajor_axis();
  const double& semimajor_axis() const;
  double& inverse_flattening();
  const double& inverse_flattening() const;

  void ImportFromWKT(const std::string& wkt);

private:

  //角度单位
  std::string angular_unit_;
  double radians_per_unit_; //每单位弧度

  //本初子午线
  std::string prime_meridian_;  //名称
  double prime_meridian_offset_;     //the longitude of Greenwich relative to this prime meridian.

  //基准面
  std::string datum_;

  //椭球体
  std::string spheroid_;
  double semimajor_axis_; //长半轴
  double inverse_flattening_;  //椭球体扁率 1/f

};

#endif