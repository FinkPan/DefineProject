#ifndef _DEFINEPROJECT_READ_WRITE_FILE_HPP_
#define _DEFINEPROJECT_READ_WRITE_FILE_HPP_

#include <string>
#include <QStringList>

#include "gdal_priv.h"
#include "cpl_conv.h"
#include <ogr_spatialref.h>

#include "coordinate_system_item.hpp"

#include <boost/property_tree/ptree.hpp> 
#include <boost/property_tree/xml_parser.hpp>

class ReadWriteFile
{
public:
  static void WriteCoordinateSystem(const std::string& filename);

  static void ReadCoordinateSystem(
    const std::string& filename,
    CoordinateSystemItem& root_item);

  static int ReNameTiffFiles(
    const QStringList& filelist,
    const QString& output_dir,
    const CoordinateSystemItem* item);

protected:
private:
  int ReadTiffFile(
    const std::string& file_path, 
    GDALDataset* poDataset,
    bool read_only);
};



#endif
