#include "handle.hh"

Handle::Handle(char* argv)
{
  __FILE__OPEN__ = fopen(argv, "w+");
}

Handle::~Handle()
{
}

void Handle::file(std::string argv)
{
  __cmd__ << "file " << argv;
  std::system(__cmd__.str().c_str());
  return;
}

void Handle::less(std::string argv)
{
  std::stringstream __cmd__;
  __cmd__ << "less " << argv;
  std::system(__cmd__.str().c_str());
  return;
}

void Handle::size(std::string argv)
{
  std::stringstream __cmd__;
  __cmd__ << "du -sh " << argv;
  std::system(__cmd__.str().c_str());
  return;	
}
