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

  //�Ƕȵ�λ
  std::string angular_unit_;
  double radians_per_unit_; //ÿ��λ����

  //����������
  std::string prime_meridian_;  //����
  double prime_meridian_offset_;     //the longitude of Greenwich relative to this prime meridian.

  //��׼��
  std::string datum_;

  //������
  std::string spheroid_;
  double semimajor_axis_; //������
  double inverse_flattening_;  //��������� 1/f

};

#endif