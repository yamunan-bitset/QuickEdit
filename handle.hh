#ifndef __HANDLE__HH__
#define __HANDLE__HH__
#include <string>
#include <sstream>

class Handle
{
public:
  Handle (std::ofstream __FILE__OPEN__);
  
  std::string input;
  static std::stringstream __cmd__;

  void file(char*);
  void less(char*);
  void cat (char*);
  void size(char*);
  void n();
};

#endif
