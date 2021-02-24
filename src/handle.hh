#ifndef __HANDLE__HH__
#define __HANDLE__HH__
#include <string>
#include <sstream>
#include <stdio.h>

#include "less.hh"

class Handle
{
public:
  Handle   (char*); // ctor
  ~Handle  ();      // dtor

  FILE* __FILE__OPEN__;
  std::string input;
  static std::stringstream __cmd__;

  // Handle Events
  void file (std::string);
  void less (std::string);
  void cat  (std::string);
  void size (std::string);
  void n    (std::string);
  void write(std::string);
};

#endif
