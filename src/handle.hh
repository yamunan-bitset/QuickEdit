#ifndef __HANDLE__HH__
#define __HANDLE__HH__
#include <string>
#include <sstream>

class Handle
{
public:
  Handle (char* argv[]); // ctor
  ~Handle(); // dtor
  
  std::string input;
  char* __m_File__;
  static std::stringstream __cmd__;

  void file(char*);
  void less(char*);
  void cat (char*);
  void size(char*);
  void n();
};

#endif
