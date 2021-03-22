#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdio>

#include "handle.hh"
#include "colours.hh"

#define NDEBUG // For assert
#define MODE "w+"
#define USAGE std::cout << red << "Usage: filename" << std::endl
static bool done = false;

int main(int argc, char* argv[])
{
  // Setup
  char* openfile;
  std::vector <std::string> x;
  std::string input;
  
  // Arguments
  if      (argc != 2) goto Use;
  else if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") goto Help;
  else openfile = argv[1];

  // Opening file
  FILE* OpenFile;
  OpenFile = fopen(openfile, MODE);
  std::cout << yellow << "Opening file: " << openfile << std::endl;
  fputs("\n", OpenFile);
  goto Loop;
    
Loop:
  // Mainloop
  while (!done)
    {
      std::cout << white << "";
      std::cin >> input;
      if (input == ":q!")    {done = true; goto End;}
      if (input == ":less!") Handle::less(openfile);
      if (input == ":n!")    fputs("\n", OpenFile);
      if (input == ":size!") Handle::size(OpenFile);
      if (input == ":cat!")  Handle::cat(openfile);
      if (input == ":e!")    Handle::edit(OpenFile, openfile);
      if (input == ":w!")    {assert(!done); goto Write;}
      else                   x.push_back(input);
    }

End:
  assert(done);
  fclose(OpenFile);

  return 0;

Write:
  std::cout << green << "Wrote: ";
  for (std::string u: x)
    {
      fputs(u.c_str(), OpenFile);
      std::cout << u;
      x.clear();
    }
  std::cout << " to file: " << openfile << std::endl;
  goto Loop;
  
Use: // Usage
  USAGE;
  exit(0);

Help: // Help
  std::cout << purple << "qui <FILE>" << std::endl;
}
