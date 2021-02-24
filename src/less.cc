#include "less.hh"

Less::Less ()
{
}

Less::~Less()
{
}

void Less::Read(std::string __m_FILE__)
{
  std::string text;
  std::ifstream __FILE__OPEN__(__m_FILE__);
  while (!__FILE__OPEN__.eof())
    getline(__FILE__OPEN__, text);std::cout << text << std::endl;
  return;
}
