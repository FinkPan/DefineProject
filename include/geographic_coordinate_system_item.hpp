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