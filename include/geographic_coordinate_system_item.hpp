#ifndef _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_ITEM_HPP_
#define _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_ITEM_HPP_

#include <string>
#include <QString>
#include "coordinate_system_item.hpp"

class GeographicCoordinateSystemItem : public CoordinateSystemItem
{
public:
  explicit GeographicCoordinateSystemItem(
    QVariant item_name,
    ItemType item_type,
    CoordinateSystemItem *parent_item = nullptr);
  ~GeographicCoordinateSystemItem();

  QString Text();

  std::string& angular_unit();
  double& radians_per_unit();

  std::string& prime_meridian();
  double& prime_meridian_offset();

  std::string& datum();

  std::string& spheroid();
  double& semimajor_axis();
  double& inverse_flattening();

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