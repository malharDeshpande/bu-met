#include "lib/Encoder.h"
#include <iostream>
#include <string>

int
main(int argc, char* argv[])
{
  bool self_test = false;
  std::string str;
  if (argc > 2) {
    if (std::string(argv[1]).compare("-t") == 0) {
      self_test = true;
      str = argv[2];
    }
  }

  if (self_test) {
    tgl::Encoder encoder;

    tgl::BigInteger encoded = encoder.encode(str);
    std::cout << "TRACE - encoded " << encoded << std::endl;

    std::string decoded = encoder.decode(encoded);
    std::cout << "TRACE - decoded " << decoded << std::endl;
  }

  return 0;
}// main
