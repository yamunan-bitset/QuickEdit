#ifndef __HANDLE__SDFSDFSDFSDF__QUI__HH__
#define __HANDLE__SDFSDFSDFSDF__QUI__HH__

#include <string>
#include <sstream>
#include <fstream>
#include "colours.hh"

namespace Handle
{
  void less(char* openfile)
  {
    std::stringstream __cmd__;
    __cmd__ << "less " << openfile;
    std::system(__cmd__.str().c_str());
    return;
  }
  void cat(char* openfile)
  {
    FILE* f = fopen(openfile, "r");
    char contents;
    while ((contents = fgetc(f)) != EOF)
      std::cout << colours << cyan << colour << contents;
    
    std::cout << std::endl;
    fclose(f);
    return;
  }
  void size(FILE* OpenFile)
  {
    fseek(OpenFile, 0L, SEEK_END); 
    long int filesize = ftell(OpenFile);
    std::cout << filesize << std::endl; 
  }
  void edit(FILE* OpenFile, char* openfile)
  { // TODO
    return;
  }
}
#endif
