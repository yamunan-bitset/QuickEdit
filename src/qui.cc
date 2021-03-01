#include <iostream>
#include <vector>
#include <stdio.h>

#include "handle.hh"
#include "colours.hh"

#define USAGE std::cout << colours << red << "mUsage: filename" << std::endl;
static bool done = false;

int main(int argc, char* argv[])
{
  char* openfile;
  std::vector <std::string> x;
  std::string input;
  
  if (argc != 2)
    {
      USAGE;
      exit(0);
    }
  else if (argv[1] == "-h" || argv[1] == "--help")
    std::cout << colours << purple << "mqui <FILE>" << std::endl;
  else openfile = argv[1];

  FILE* OpenFile;
  OpenFile = fopen(openfile, "w+");
  fputs("\n", OpenFile);
  
  while (!done)
    {
      std::cin >> input;
      if (input == ":q!") done = true;
      else if (input == ":less!") Handle::less(openfile);
      else if (input == ":n!") fputs("\n", OpenFile);
      else if (input == ":size!") Handle::size(OpenFile);
      else if (input == ":cat!")  Handle::cat(openfile);
      else
	{
	  x.push_back(input);
	  fputs(input.c_str(), OpenFile);
	}   
    }
  
  fclose(OpenFile);
  std::cout << colours << green << "mWrote: ";
  for (std::string u: x)
    std::cout << u;
  std::cout << " to file: " << openfile << std::endl;
  
  return 0;
}
