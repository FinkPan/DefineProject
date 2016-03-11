#include <iostream>
#include <QString>
#include <QObject>
#include <boost/foreach.hpp>

#include "read_write_file.hpp"
#include "geographic_coordinate_system_item.hpp"
#include "projected_coordinate_system_item.hpp"

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
  CoordinateSystemModel& model)
{
  std::ifstream input_file(filename);
  std::string line;
  while(getline(input_file,line))
  {
    model.add_item(QString::fromStdString(line));
  }
}

// void ReadWriteFile::ReadCoordinateSystem(
//   const std::string& filename,
//   CoordinateSystemItem& root_item)
// {
//   using boost::property_tree::ptree;
//   ptree root;
//   read_xml(filename, root); 
// 
//   BOOST_FOREACH(ptree::value_type &v_cs,root.get_child("Coordinate_System"))
//   {
//     if (v_cs.first == "Geographic_coordinate_system")
//     {
//       CoordinateSystemItem* cs_item = new CoordinateSystemItem(
//         QObject::tr("Geographic Coordinate System"),
//         CoordinateSystemItem::FOLDER_CLOSE,&root_item);
//       BOOST_FOREACH(ptree::value_type &v_gcs,v_cs.second)
//       {
//         GeographicCoordinateSystemItem* gcs_item = 
//           new GeographicCoordinateSystemItem(
//           QVariant(v_gcs.first.c_str()),
//           CoordinateSystemItem::GEOGRAPHIC_COORDINATE_SYSTEM,cs_item);
//         gcs_item->wkid() = v_gcs.second.get<int>("WKID");
//         gcs_item->angular_unit() = v_gcs.second.get<std::string>("angular_unit");
//         gcs_item->radians_per_unit() = v_gcs.second.get<double>("radians_per_unit");
//         gcs_item->prime_meridian() = v_gcs.second.get<std::string>("prime_meridian");
//         gcs_item->prime_meridian_offset() = v_gcs.second.get<double>("prime_meridian_offset");
//         gcs_item->datum() = v_gcs.second.get<std::string>("datum");
//         gcs_item->spheroid() = v_gcs.second.get<std::string>("spheroid");
//         gcs_item->semimajor_axis() = v_gcs.second.get<double>("semimajor_axis");
//         gcs_item->inverse_flattening() = v_gcs.second.get<double>("inverse_flattening");
//       }
//     }
//     else if (v_cs.first == "Projected_coordinate_system")
//     {
//       CoordinateSystemItem* cs_item = new CoordinateSystemItem(
//         QObject::tr("Projected_coordinate_system"),
//         CoordinateSystemItem::FOLDER_CLOSE,&root_item);
//       BOOST_FOREACH(ptree::value_type &v_pn,v_cs.second)
//       {
//         CoordinateSystemItem* pn_item = new CoordinateSystemItem(
//           QVariant(v_pn.first.c_str()),
//           CoordinateSystemItem::FOLDER_CLOSE,cs_item);
//         BOOST_FOREACH(ptree::value_type &v_csn, v_pn.second)
//         {
//           CoordinateSystemItem* pcns_item = new CoordinateSystemItem(
//             QVariant(v_csn.first.c_str()),
//             CoordinateSystemItem::FOLDER_CLOSE,pn_item);
//           BOOST_FOREACH(ptree::value_type &v_pcsn,v_csn.second)
//           {
//             ProjectedCoordinateSystemItem* pcnsn_item = 
//               new ProjectedCoordinateSystemItem(
//               QVariant(v_pcsn.first.c_str()),
//               CoordinateSystemItem::PROJECTED_COORDINATE_SYSTEM,pcns_item);
//             pcnsn_item->wkid() = v_pcsn.second.get<int>("WKID");
//             pcnsn_item->gcs_wkid() = v_pcsn.second.get<int>("GCS_WKID");
//             pcnsn_item->projection() = v_pcsn.second.get<std::string>("projection");
//             pcnsn_item->false_easting() = v_pcsn.second.get<double>("false_easting");
//             pcnsn_item->false_northing() = v_pcsn.second.get<double>("false_northing");
//             pcnsn_item->central_meridian() = v_pcsn.second.get<double>("central_meridian");
//             pcnsn_item->scale_factor() = v_pcsn.second.get<double>("scale_factor");
//             pcnsn_item->latitude_of_origin() = v_pcsn.second.get<double>("latitude_of_origin");
//             pcnsn_item->linear_unit_name() = v_pcsn.second.get<std::string>("linear_unit_name");
//             pcnsn_item->linear_unit() = v_pcsn.second.get<double>("linear_unit");
//           }
//         }
//       }
//     }
//   }
// }

// int ReadWriteFile::ReNameTiffFiles(
//     const QStringList& filelist,
//     const QString& output_dir,
//     const GeographicCoordinateSystemItem* gcs_item,
//     const ProjectedCoordinateSystemItem* pcs_item)
// {
//   if (gcs_item == nullptr)
//   {
//     return -1;
//   }
// 
//   QStringList false_files;
//   GDALAllRegister();
// 
//   for(const auto& file : filelist)
//   {
//     GDALDataset *poDataset = NULL;
//     GDALDataset *poDataset_dummy = NULL;
//     GDALDriver *poDriver;
//     double  dfGeoTransform[6];
// 
//     if(output_dir.isEmpty())
//     {
//       poDataset = (GDALDataset *)GDALOpen(file.toStdString().c_str(),GA_Update);
//       if(poDataset == NULL)
//       {
//         false_files.append(file);
//         break;
//       }
//     }
//     else
//     {
//       poDataset = (GDALDataset *)GDALOpen(file.toStdString().c_str(),GA_ReadOnly);
//       poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
//       if(poDriver == NULL)
//       {
//         false_files.append(file);
//         break;
//       }
//       poDataset_dummy =
//         poDriver->CreateCopy(file.toStdString().c_str(),
//           poDataset,FALSE,NULL,NULL,NULL);
//       if(poDataset_dummy == NULL)
//       {
//         false_files.append(file);
//         break;
//       }
//     }
// 
// 
//     //poDataset->GetGeoTransform(dfGeoTransform);
// 
//     OGRSpatialReference oSRS;
//     char *pszSRS_WKT = NULL;
// 
//     oSRS.SetGeogCS(
//       gcs_item->item_name().toString().toStdString().c_str(),
//       gcs_item->datum().c_str(),
//       gcs_item->spheroid().c_str(),
//       gcs_item->semimajor_axis(),
//       gcs_item->inverse_flattening(),
//       gcs_item->prime_meridian().c_str(),
//       gcs_item->prime_meridian_offset(),
//       gcs_item->angular_unit().c_str(),
//       gcs_item->radians_per_unit());
// 
//     if (pcs_item != nullptr)
//     {
//       oSRS.SetProjCS(pcs_item->item_name().toString().toStdString().c_str());
//       oSRS.SetProjection(pcs_item->projection().c_str());
// 
//       oSRS.SetProjParm("latitude_of_origin",pcs_item->latitude_of_origin());
//       oSRS.SetProjParm("central_meridian",pcs_item->central_meridian());
//       oSRS.SetProjParm("scale_factor",pcs_item->scale_factor());
//       oSRS.SetProjParm("false_easting",pcs_item->false_easting());
//       oSRS.SetProjParm("false_northing",pcs_item->false_northing());
//     }
//     
//     oSRS.exportToWkt(&pszSRS_WKT);
// 
//     std::cout << "=======================\n";
//     std::cout << pszSRS_WKT;
//     std::cout << "\n=======================\n";
// 
//     char* temp = "PROJCS[\"Beijing_1954_3_Degree_GK_CM_105E\",GEOGCS[\"GCS_Beijing_1954\",DATUM[\"D_Beijing_1954\",SPHEROID[\"Krasovsky_1940\",6378245.0,298.3]],PRIMEM[\"Greenwich\",0.0],UNIT[\"Degree\",0.0174532925199433]],PROJECTION[\"Gauss_Kruger\"],PARAMETER[\"False_Easting\",500000.0],PARAMETER[\"False_Northing\",0.0],PARAMETER[\"Central_Meridian\",105.0],PARAMETER[\"Scale_Factor\",1.0],PARAMETER[\"Latitude_Of_Origin\",0.0],UNIT[\"Meter\",1.0]]";
// 
// 
// 
//     if(output_dir.isEmpty())
//     {
//       CPLErr re2 = poDataset->SetProjection(temp);
//       if (re2 == CE_Failure)
//       {
//         false_files.append(file);
//         std::cout << "SetProjection Error.\n";
//       }
//     }
//     else
//     {
//       CPLErr re2 = poDataset_dummy->SetProjection(pszSRS_WKT);
//       if(re2 == CE_Failure)
//       {
//         false_files.append(file);
//         std::cout << "SetProjection Error.\n";
//       }
//     }
// 
//     CPLFree(pszSRS_WKT);
// 
//     if (poDataset != NULL)
//       GDALClose((GDALDatasetH)poDataset);
//     
//     if (poDataset_dummy != NULL)
//       GDALClose((GDALDatasetH)poDataset_dummy);
// 
//   }
// 
//   return 0;
// }


int ReadWriteFile::ReadCoordinateSystemWriteXML(
  const QStringList& filelist,
  const QString& output_dir)
{
  using boost::property_tree::ptree;
  ptree root;
  ptree node;
  std::string filename = output_dir.toStdString() + "/coordinate_system.txt";
  std::ofstream out_file(filename,std::ios_base::app);

  for (const auto &file : filelist)
  {
    std::ifstream input_file(file.toStdString());
    std::string line;
    getline(input_file,line);


    out_file << line << "\n";
  }
//     OGRSpatialReference oSRS;
//     char *buf = new char[line.size()];
//     strcpy(buf,line.c_str());
//     oSRS.importFromWkt(&buf);
//     bool is_pcs = oSRS.IsProjected();
//     char *wkt = NULL;
//     oSRS.exportToWkt(&wkt);
// 
//     if (is_pcs)
//     {
//       const char* pro_name = oSRS.GetAttrValue("PROJECTION");
//       std::string str_val = std::string();
// 
//       std::string str_node;
//       str_node = "Projected_coordinate_system." +
//         std::string(oSRS.GetAttrValue("PROJECTION")) + "." + 
//         std::string(oSRS.GetAttrValue("PROJCS"));
//       node.add(str_node,line);
//     }
//     else
//     {
// //       node.add("Geographic_coordinate_system.GCS_China_Geodetic_Coordinate_System_2000","");
// 
//     }
//     
// 
//   }
  
//   root.add_child("Coordinate_System",node);
//   std::string filename = output_dir.toStdString() + "/coordinate_system.xml";
//   boost::property_tree::xml_parser::xml_writer_settings<
//     boost::property_tree::ptree::key_type> settings(' ',2);
//   write_xml(filename,root,std::locale(),settings);
// 
//   ptree root1;
//   read_xml(filename,root1);
//   BOOST_FOREACH(ptree::value_type &v_cs,root.get_child("Coordinate_System"))
//   {
//     if(v_cs.first == "Projected_coordinate_system")
//     {
//       BOOST_FOREACH(ptree::value_type &v_gcs,v_cs.second)
//       {
//         std::cout << "name: " << v_gcs.first;
//       }
//     }
//   }

  return 0;
}
