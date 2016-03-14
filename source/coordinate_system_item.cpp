#include <iostream>

#include "coordinate_system_item.hpp"

CoordinateSystemItem::CoordinateSystemItem(
  const QString& wkt,
  ItemType item_type,
  CoordinateSystemItem *parent_item)
  : item_type_(item_type)
  , parent_item_(parent_item)
{
  QByteArray ba_wkt = wkt.toLatin1();
  char *c_wkt = ba_wkt.data();

  oSRS_.importFromWkt(&c_wkt);
  if(oSRS_.IsGeographic())
  {
    item_name_ = QString(oSRS_.GetAttrValue("GEOGCS"));
  }
  else if(oSRS_.IsProjected())
  {
    item_name_ = QString(oSRS_.GetAttrValue("PROJCS"));
  }
  else
    item_name_ = wkt;
  
  if(parent_item_ != nullptr)
    parent_item_->add_child_item(this);
}

CoordinateSystemItem::~CoordinateSystemItem()
{  
  qDeleteAll(child_items_);
}

void CoordinateSystemItem::add_child_item(CoordinateSystemItem* item)
{
  child_items_.append(item);
}

CoordinateSystemItem *CoordinateSystemItem::child(int row)
{
    return child_items_.value(row);
}

int CoordinateSystemItem::childCount() const
{
    return child_items_.count();
}

int CoordinateSystemItem::columnCount() const
{
  if (item_name_.isNull())
    return 0;
  else
    return 1;
}

CoordinateSystemItem *CoordinateSystemItem::parent_item() const
{
    return parent_item_;
}

int CoordinateSystemItem::row() const
{
    if (parent_item_)
        return parent_item_->child_items_.indexOf(
          const_cast<CoordinateSystemItem*>(this));

    return 0;
}

CoordinateSystemItem* CoordinateSystemItem::child_item(int i) const
{
  int num_item = childCount();
  if (i <= num_item)
  {
    return child_items_[i];
  }
  return nullptr;
}


void CoordinateSystemItem::set_item_type(ItemType item_type)
{
  item_type_ = item_type;
}

QVariant CoordinateSystemItem::item_name() const
{
  return item_name_;
}

CoordinateSystemItem::ItemType CoordinateSystemItem::item_type() const
{
  return item_type_;
}

const OGRSpatialReference& CoordinateSystemItem::oSRS() const
{
  return oSRS_;
}

QString CoordinateSystemItem::Text()
{
  if(oSRS_.IsGeographic())
  {
    return GCSText();
  }
  else if(oSRS_.IsProjected())
  {
    return PCSText();
  }
  else
    return item_name_.toString();
}


QString CoordinateSystemItem::GCSText() const
{
  char* angular_unit = nullptr;
  double angular_unit_value = oSRS_.GetAngularUnits(&angular_unit);
  char* prime_meridian = nullptr;
  double prime_meridian_value = oSRS_.GetPrimeMeridian(&prime_meridian);

return QString(
"%1\n\
%2: %3\n\n\
Angular Unit: %4 (%5)\n\
Prime Meridian: %6 (%7)\n\
Datum: %8\n\
  Spheroid: %9\n\
  Semimajor Axis: %10\n\
  Inverse Flattening: %11\n\
")
.arg(item_name_.toString())
.arg(QString(oSRS_.GetAuthorityName("GEOGCS")))
.arg(QString(oSRS_.GetAuthorityCode("GEOGCS")))
.arg(QString(angular_unit)).arg(angular_unit_value)
.arg(QString(prime_meridian)).arg(prime_meridian_value)
.arg(QString(oSRS_.GetAttrValue("DATUM")))
.arg(QString(oSRS_.GetAttrValue("SPHEROID")))
.arg(oSRS_.GetSemiMajor(),0,'f')
.arg(oSRS_.GetInvFlattening());
}

QString CoordinateSystemItem::PCSText() const
{
  char* linear_unit_name = nullptr;
  double linear_unit = oSRS_.GetTargetLinearUnits("PROJCS",&linear_unit_name);
  char* angular_unit = nullptr;
  double angular_unit_value = oSRS_.GetAngularUnits(&angular_unit);
  char* prime_meridian = nullptr;
  double prime_meridian_value = oSRS_.GetPrimeMeridian(&prime_meridian);

  return QString(
"%1\n\
%2: %3\n\n\
Projection: %4\n\
False Easting: %5\n\
False Northing: %6\n\
Central Meridian: %7\n\
Scale Factor: %8\n\
Latitude Of Origin: %9\n\
Linear Unit: %10 (%11)\n\n"
)
.arg(item_name_.toString())
.arg(QString(oSRS_.GetAuthorityName("PROJCS")))
.arg(QString(oSRS_.GetAuthorityCode("PROJCS")))
.arg(QString(oSRS_.GetAttrValue("PROJECTION")))
.arg(oSRS_.GetProjParm(SRS_PP_FALSE_EASTING),0,'f')
.arg(oSRS_.GetProjParm(SRS_PP_FALSE_NORTHING),0,'f')
.arg(oSRS_.GetProjParm(SRS_PP_CENTRAL_MERIDIAN))
.arg(oSRS_.GetProjParm(SRS_PP_SCALE_FACTOR),0,'f')
.arg(oSRS_.GetProjParm(SRS_PP_LATITUDE_OF_ORIGIN))
.arg(QString(linear_unit_name)).arg(linear_unit) + 
QString(
"Geographic Coordinate System: %1\n\
Angular Unit: %2 (%3)\n\
Prime Meridian: %4 (%5)\n\
Datum: %6\n\
  Spheroid: %7\n\
    Semimajor Axis: %8\n\
      Inverse Flattening: %9\n\
      ")
.arg(QString(oSRS_.GetAttrValue("GEOGCS")))
.arg(QString(angular_unit)).arg(angular_unit_value,0,'f')
.arg(QString(prime_meridian)).arg(prime_meridian_value)
.arg(QString(oSRS_.GetAttrValue("DATUM")))
.arg(QString(oSRS_.GetAttrValue("SPHEROID")))
.arg(oSRS_.GetSemiMajor(),1,'f')
.arg(oSRS_.GetInvFlattening());

}