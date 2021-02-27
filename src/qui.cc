#include <iostream>
#include <vector>
#include <stdio.h>

#include "handle.hh"

#define USAGE "\033[31mUsage: filename" // red
static bool done = false;

int main(int argc, char* argv[])
{
  char* openfile;
  std::vector <std::string> x;
  std::string input;
  
  if (argc != 2)
    {
      std::cerr << USAGE << std::endl;
      exit(0);
    }
  else if (argv[1] == "-h" || argv[1] == "--help")
    std::cout << "\033[95mqui <FILE>" << std::endl; // light purple
  else openfile = argv[1];

  FILE* OpenFile;
  OpenFile = fopen(openfile, "w+");

  while (!done)
    {
      std::cin >> input;
      if (input == ":q!") done = true;
      if (input == ":less!") Handle::less(OpenFile);
      else
	{
	  x.push_back(input);
	  fputs(input.c_str(), OpenFile);
	}
    }
  
  fclose(OpenFile);


  std::cout << "\033[32mWrote: "; // green
  for (std::string u: x)
    std::cout << u;
  std::cout << " to file: " << openfile << std::endl;
  
  return 0;
}
