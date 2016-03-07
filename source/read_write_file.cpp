#include <iostream>
#include <QString>
#include <QObject>
#include <boost/foreach.hpp>
#include "read_write_file.hpp"
#include "geographic_coordinate_system.hpp"
#include "projected_coordinate_system.hpp"

void ReadWriteFile::WriteCoordinateSystem(const std::string& filename)
{
  using boost::property_tree::ptree;
  ptree root;
  ptree node;
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000","");
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.WKID",4490);
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.angular_unit","Degree");
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.radians_per_unit",0.0174532925199433);
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.prime_meridian","Greenwich");
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.prime_meridian_offset",0.0);
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.datum","D_China_2000");
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.spheroid","CGCS2000");
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.semimajor_axis", 6378137.0);
  node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000.inverse_flattening", 298.257222101);

  node.add("Geographic_coordinate_system.GCS_Beijing_1954","");
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.WKID",4214);
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.angular_unit","Degree");
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.radians_per_unit",0.0174532925199433);
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.prime_meridian","Greenwich");
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.prime_meridian_offset",0.0);
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.datum","D_Beijing_1954");
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.spheroid","Krasovsky_1940");
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.semimajor_axis",6378245.0);
  node.add("Geographic_coordinate_system.GCS_Beijing_1954.inverse_flattening",298.3);

  node.add("Geographic_coordinate_system.GCS_WGS_1984","");
  node.add("Geographic_coordinate_system.GCS_WGS_1984.WKID",4326);
  node.add("Geographic_coordinate_system.GCS_WGS_1984.angular_unit","Degree");
  node.add("Geographic_coordinate_system.GCS_WGS_1984.radians_per_unit",0.0174532925199433);
  node.add("Geographic_coordinate_system.GCS_WGS_1984.prime_meridian","Greenwich");
  node.add("Geographic_coordinate_system.GCS_WGS_1984.prime_meridian_offset",0.0);
  node.add("Geographic_coordinate_system.GCS_WGS_1984.datum","D_WGS_1984");
  node.add("Geographic_coordinate_system.GCS_WGS_1984.spheroid","WGS_1984");
  node.add("Geographic_coordinate_system.GCS_WGS_1984.semimajor_axis",6378137.0);
  node.add("Geographic_coordinate_system.GCS_WGS_1984.inverse_flattening",298.257223563);


  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E","");
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.WKID",4548);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.GCS_WKID",4490);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.projection","Gauss_Kruger");
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.false_easting",500000.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.false_northing",0.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.central_meridian",117.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.scale_factor",1.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.latitude_of_origin",0.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.linear_unit_name","Meter");
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_117E.linear_unit",1.0);

  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E","");
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.WKID",4549);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.GCS_WKID",4490);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.projection","Gauss_Kruger");
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.false_easting",500000.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.false_northing",0.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.central_meridian",120.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.scale_factor",1.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.latitude_of_origin",0.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.linear_unit_name","Meter");
  node.add("Projected_coordinate_system.Gauss_Kruger.CGCS2000.CGCS2000_3_Degree_GK_CM_120E.linear_unit",1.0);

  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E","");
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.WKID",2437);
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.GCS_WKID",4214);
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.projection","Gauss_Kruger");
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.false_easting",500000.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.false_northing",0.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.central_meridian",120.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.scale_factor",1.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.latitude_of_origin",0.0);
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.linear_unit_name","Meter");
  node.add("Projected_coordinate_system.Gauss_Kruger.Beijing54.Beijing_1954_3_Degree_GK_CM_120E.linear_unit",1.0);

  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N","");
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.WKID",32637);
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.GCS_WKID",4326);
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.projection","Transverse_Mercator");
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.false_easting",500000.0);
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.false_northing",0.0);
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.central_meridian",39.0);
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.scale_factor",0.9996);
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.latitude_of_origin",0.0);
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.linear_unit_name","Meter");
  node.add("Projected_coordinate_system.UTM.WGS84.WGS_1984_UTM_Zone_37N.linear_unit",1.0);

  root.add_child("Coordinate_System",node);

  boost::property_tree::xml_parser::xml_writer_settings<
    boost::property_tree::ptree::key_type> settings(' ',2);
  write_xml(filename,root,std::locale(),settings);
}

void ReadWriteFile::ReadCoordinateSystem(
  const std::string& filename,
  CoordinateSystemItem& root_item)
{
  using boost::property_tree::ptree;
  ptree root;
  read_xml(filename, root); 

  BOOST_FOREACH(ptree::value_type &v_cs,root.get_child("Coordinate_System"))
  {
    if (v_cs.first == "Geographic_coordinate_system")
    {
      CoordinateSystemItem* cs_item = new CoordinateSystemItem(
        QObject::tr("Geographic Coordinate System"),
        CoordinateSystemItem::FOLDER_CLOSE,&root_item);
      BOOST_FOREACH(ptree::value_type &v_gcs,v_cs.second)
      {
        CoordinateSystemItem* gcs_item = new CoordinateSystemItem(
          QVariant(v_gcs.first.c_str()),
          CoordinateSystemItem::GEOGRAPHIC_COORDINATE_SYSTEM,cs_item);
        GeographicCoordinateSystem* gcs_temp = new GeographicCoordinateSystem;
        gcs_temp->name() = v_gcs.first;
        gcs_temp->wkid() = v_gcs.second.get<int>("WKID");
        gcs_temp->angular_unit() = v_gcs.second.get<std::string>("angular_unit");
        gcs_temp->radians_per_unit() = v_gcs.second.get<double>("radians_per_unit");
        gcs_temp->prime_meridian() = v_gcs.second.get<std::string>("prime_meridian");
        gcs_temp->prime_meridian_offset() = v_gcs.second.get<double>("prime_meridian_offset");
        gcs_temp->datum() = v_gcs.second.get<std::string>("datum");
        gcs_temp->spheroid() = v_gcs.second.get<std::string>("spheroid");
        gcs_temp->semimajor_axis() = v_gcs.second.get<double>("semimajor_axis");
        gcs_temp->inverse_flattening() = v_gcs.second.get<double>("inverse_flattening");
        gcs_item->set_item_data(gcs_temp);
      }
    }
    else if (v_cs.first == "Projected_coordinate_system")
    {
      CoordinateSystemItem* cs_item = new CoordinateSystemItem(
        QObject::tr("Projected_coordinate_system"),
        CoordinateSystemItem::FOLDER_CLOSE,&root_item);
      BOOST_FOREACH(ptree::value_type &v_pn,v_cs.second)
      {
        CoordinateSystemItem* pn_item = new CoordinateSystemItem(
          QVariant(v_pn.first.c_str()),
          CoordinateSystemItem::FOLDER_CLOSE,cs_item);
        BOOST_FOREACH(ptree::value_type &v_csn, v_pn.second)
        {
          CoordinateSystemItem* pcns_item = new CoordinateSystemItem(
            QVariant(v_csn.first.c_str()),
            CoordinateSystemItem::FOLDER_CLOSE,pn_item);
          BOOST_FOREACH(ptree::value_type &v_pcsn,v_csn.second)
          {
            CoordinateSystemItem* pcnsn_item = new CoordinateSystemItem(
              QVariant(v_pcsn.first.c_str()),
              CoordinateSystemItem::PROJECTED_COORDINATE_SYSTEM,pcns_item);
            ProjectedCoordinateSystem* pcs_temp = new ProjectedCoordinateSystem;
            pcs_temp->name() = v_pcsn.first;
            pcs_temp->wkid() = v_pcsn.second.get<int>("WKID");
            pcs_temp->gcs_wkid() = v_pcsn.second.get<int>("GCS_WKID");
            pcs_temp->projection() = v_pcsn.second.get<std::string>("projection");
            pcs_temp->false_easting() = v_pcsn.second.get<double>("false_easting");
            pcs_temp->false_northing() = v_pcsn.second.get<double>("false_northing");
            pcs_temp->central_meridian() = v_pcsn.second.get<double>("central_meridian");
            pcs_temp->scale_factor() = v_pcsn.second.get<double>("scale_factor");
            pcs_temp->latitude_of_origin() = v_pcsn.second.get<double>("latitude_of_origin");
            pcs_temp->linear_unit_name() = v_pcsn.second.get<std::string>("linear_unit_name");
            pcs_temp->linear_unit() = v_pcsn.second.get<double>("linear_unit");
            pcnsn_item->set_item_data(pcs_temp);
          }
        }
      }
    }
  }
//        gcs.AddGCS(v.second.data()
}

int ReadWriteFile::ReNameTiffFiles(const QStringList& filelist)
{

  return 0;
}
