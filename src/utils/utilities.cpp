#include "utilities.h"

void endian_swap(unsigned short& x)
{
    x = (x>>8) |
        (x<<8);
}

inline void endian_swap(unsigned int& x)
{
    x = (x>>24) |
        ((x<<8) & 0x00FF0000) |
        ((x>>8) & 0x0000FF00) |
        (x<<24);
}

// __int64 for MSVC, "long long" for gcc
inline void endian_swap(unsigned long long& x)
{
    x = (x>>56) |
        ((x<<40) & 0x00FF000000000000) |
        ((x<<24) & 0x0000FF0000000000) |
        ((x<<8)  & 0x000000FF00000000) |
        ((x>>8)  & 0x00000000FF000000) |
        ((x>>24) & 0x0000000000FF0000) |
        ((x>>40) & 0x000000000000FF00) |
        (x<<56);
}


std::string getFileName(const std::string _path){
  // sanitize application name - only windows for now
  // path separator is '\' even in MSYS2 (and since Cygwin 1.7 seems)
  // could be done in Boost::Filesystem but didn't want to carry over yet
  // another BINARY dependency (boost_filesystem-mt and boost_system-mt)
  static const char* pathsep = "/\\";
  auto first = _path.find_last_of(pathsep) +1;
  auto last = _path.find_last_of('.');
  return _path.substr(first, last-first);
}

std::string getFileName(const char *_path){
  return getFileName(std::string(_path));
}

