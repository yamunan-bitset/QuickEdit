#ifndef __HANDLE__SDFSDFSDFSDF__QUI__HH__
#define __HANDLE__SDFSDFSDFSDF__QUI__HH__

#include <string>
#include <sstream>
#include <fstream>

#include "less.hh"

namespace Handle
{
  void less(char* argv)
  {
    std::stringstream __cmd__;
    __cmd__ << "less " << argv;
    std::system(__cmd__.str().c_str());
    return;
  }
  void cat(char* argv)
  {
    std::stringstream __cmd__;
    __cmd__ << "cat " << argv;
    std::system(__cmd__.str().c_str());
    return;
  }
  void size(FILE* openfile)
  {
    fseek(openfile, 0L, SEEK_END); 
    long int filesize = ftell(openfile); 
    std::cout << filesize << std::endl; 
  }
}
#endif
