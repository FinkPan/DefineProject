#ifndef _DEFINEPROJECT_READ_WRITE_FILE_HPP_
#define _DEFINEPROJECT_READ_WRITE_FILE_HPP_

#include <string>

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
protected:
private:
};



#endif
