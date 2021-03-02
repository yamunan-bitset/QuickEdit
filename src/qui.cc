#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <stdio.h>

#include "handle.hh"
#include "colours.hh"

#define USAGE std::cout << colours << red << colour << "Usage: filename" << std::endl;
#define MODE "w+"
static bool done = false;

int main(int argc, char* argv[])
{
  // Setup
  char* openfile;
  std::vector <std::string> x;
  std::string input;
  
  // Arguments
  if      (argc != 2) goto Use;
  else if (argv[1] == "-h" || argv[1] == "--help")
    goto Help;
  else openfile = argv[1];

  // Opening file
  FILE* OpenFile;
  OpenFile = fopen(openfile, MODE);
  std::cout << colours << yellow << colour << "Opening file: " << openfile << std::endl;
  fputs("\n", OpenFile);

  // Mainloop
  while (!done)
    {
      std::cout << colours << white << colour << "";
      std::cin >> input;
      if      (input == ":q!")    done = true;
      else if (input == ":less!") Handle::less(openfile);
      else if (input == ":n!")    fputs("\n", OpenFile);
      else if (input == ":size!") Handle::size(OpenFile);
      else if (input == ":cat!")  Handle::cat(openfile);
      else if (input == ":e!")    Handle::edit(OpenFile, openfile); // TODO
      else 
	{
	  x.push_back(input);
	  fputs(input.c_str(), OpenFile);
	}
    }
    
  assert (done = true);

  fclose(OpenFile);
  std::cout << colours << green << colour << "Wrote: ";
  for (std::string u: x) std::cout << u; 
  std::cout << " to file: " << openfile << std::endl;

  return 0;
  
Use: // Usage
  USAGE;
  exit(0);

Help: // Help
  std::cout << colours << purple << colour << "qui <FILE>" << std::endl;  
}
