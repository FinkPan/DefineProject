#ifndef _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_HPP_
#define _DEFINEPROJECT_GEOGRAPHIC_COORDINATE_SYSTEM_HPP_

#include <QString>
#include <QVariant>

struct GCS
{
  //����
  QString GCS_name_;

  //��׼��
  QString datum_name_;

  //������
  QString spheroid_name_;
  double semimajor_; //������
  double inverse_flattening_;  //��������� 1/f

  //�Ƕȵ�λ
  QString angular_unit_name_;
  double radians_per_unit_; //ÿ��λ����

  //����������
  QString prime_meridian_name_;  //����
  double prime_meridian_offset_;     //the longitude of Greenwich relative to this prime meridian.


};


#endif