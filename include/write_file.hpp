#ifndef _DEFINEPROJECT_WRITE_FILE_HPP_
#define _DEFINEPROJECT_WRITE_FILE_HPP_

#include <string>

#include <boost/property_tree/ptree.hpp> 
#include <boost/property_tree/xml_parser.hpp>

class WriteFile
{
public:
  static void WriteCoordinateSystem(const std::string& path);
protected:
private:
};



#endif
