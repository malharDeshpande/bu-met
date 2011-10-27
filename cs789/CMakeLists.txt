PROJECT(CS789)

ADD_EXECUTABLE(gcd
  gcd.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/EuclideanAlgorithm.cpp)

ADD_EXECUTABLE(egcd
  egcd.cpp
  lib/ExpandedEuclideanAlgorithm.cpp)

ADD_EXECUTABLE(pow
  pow.cpp
  lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(pow_mod
  pow_mod.cpp
  lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(big_int
        big_int.cpp
        lib/BigInteger.cpp
        lib/BigUnsigned.cpp)
