#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <stdio.h>

#include "handle.hh"
#include "colours.hh"

#define NDEBUG // For assert (debuging may be an issue)
#define MODE "w+"
#define USAGE std::cout << colours << red << colour << "Usage: filename" << std::endl
static bool done = false;

int main(int argc, char* argv[])
{
  // Setup
  char* openfile;
  std::vector <std::string> x;
  std::string input;
  
  // Arguments
  if      (argc != 2) goto Use;
  else if (argv[1] == "-h" || argv[1] == "--help") goto Help;
  else openfile = argv[1];

  // Opening file
  FILE* OpenFile;
  OpenFile = fopen(openfile, MODE);
  std::cout << colours << yellow << colour << "Opening file: " << openfile << std::endl;
  fputs("\n", OpenFile);
  goto Loop;
    
Loop:
  // Mainloop
  while (!done)
    {
      std::cout << colours << white << colour << "";
      std::cin >> input;
      if (input == ":q!")    {done = true; goto End;}
      if (input == ":less!") Handle::less(openfile);
      if (input == ":n!")    fputs("\n", OpenFile);
      if (input == ":size!") Handle::size(OpenFile);
      if (input == ":cat!")  Handle::cat(openfile);
      if (input == ":e!")    Handle::edit(OpenFile, openfile); // TODO
      if (input == ":w!")    {assert(!done); goto Write;}
      else                   x.push_back(input);
    }

End:
  assert(done); // Make sure done is actually true
  fclose(OpenFile);

  return 0;

Write:
  std::cout << colours << green << colour << "Wrote: ";
  for (std::string u: x)
    {
      fputs(u.c_str(), OpenFile);
      std::cout << u;
    }
  std::cout << " to file: " << openfile << std::endl;
  goto Loop;
  
Use: // Usage
  USAGE;
  exit(0);

Help: // Help
  std::cout << colours << purple << colour << "qui <FILE>" << std::endl;
}
