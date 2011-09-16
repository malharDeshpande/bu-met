PROJECT(CS789)

ADD_EXECUTABLE(gcd
  gcd.cpp
  lib/EuclideanAlgorithm.cpp)

ADD_EXECUTABLE(egcd
  egcd.cpp
  lib/ExpandedEuclideanAlgorithm.cpp)
