#ifndef _DEFINEPROJECT_COORDINATE_SYSTEM_DATA_HPP_
#define _DEFINEPROJECT_COORDINATE_SYSTEM_DATA_HPP_

#include <string>
#include <QString>

class CoordinateSystemData
{
public:
  virtual ~CoordinateSystemData() = 0;
  virtual std::string& name() = 0;
  virtual int& wkid() = 0;
  virtual QString Text() = 0; 
};


#endif
