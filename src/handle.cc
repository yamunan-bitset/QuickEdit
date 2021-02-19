#include "handle.hh"

Handle::Handle(char* argv[])
{
  std::ifstream __FILE__OPEN__;
  __FILE__OPEN__.open(argv[1]);
}

Handle::~Handle()
{
}

void Handle::file(char argv[])
{
  __FILE__OPEN__ << std::endl;
  __cmd__ << "file " << argv[1];
  std::system(__cmd__.str().c_str());
  return;
}

void Handle::less(char argv[])
{
  __FILE__OPEN__ << std::endl;
  std::stringstream __cmd__;
  __cmd__ << "less " << argv[1];
  std::system(__cmd__.str().c_str());
  return;
}

void Handle::size(char argv[])
{
  std::stringstream __cmd__;
  __cmd__ << "du -sh " << argv[1];
  std::system(__cmd__.str().c_str());
  return;	
}
