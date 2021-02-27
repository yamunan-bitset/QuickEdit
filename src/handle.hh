#ifndef __HANDLE__SDFSDFSDFSDF__QUI__HH__
#define __HANDLE__SDFSDFSDFSDF__QUI__HH__

#include <string>
#include <sstream>

#include "less.hh"

namespace Handle
{
  void less(FILE* openfile)
  {
    std::stringstream __cmd__;
    __cmd__ << "less " << openfile;
    std::system(__cmd__.str().c_str());
    return;
  }
}
#endif
