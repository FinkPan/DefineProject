#ifndef _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_HPP_
#define _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_HPP_

#include <QString>
#include <QVariant>

struct GCS
{
  //名称
  QString GCS_name_;

  //基准面
  QString datum_name_;

  //椭球体
  QString spheroid_name_;
  double semimajor_; //长半轴
  double inverse_flattening_;  //椭球体扁率 1/f

  //角度单位
  QString angular_unit_name_;
  double radians_per_unit_; //每单位弧度

  //本初子午线
  QString prime_meridian_name_;  //名称
  double prime_meridian_offset_;     //the longitude of Greenwich relative to this prime meridian.


};


#endif