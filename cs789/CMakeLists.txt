PROJECT(CS789)

ADD_EXECUTABLE(gcd
  gcd.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/EuclideanAlgorithm.cpp)

ADD_EXECUTABLE(egcd
  egcd.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/ExpandedEuclideanAlgorithm.cpp)

ADD_EXECUTABLE(pow
  pow.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(sqrt
  sqrt.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/FloorSqrtAlgorithm.cpp
  lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(pow_mod
  pow_mod.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(big_int
  big_int.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp)

ADD_EXECUTABLE(encode
  encode.cpp
  lib/Encoder.cpp
  lib/BigInteger.cpp
  lib/ExponentiationAlgorithm.cpp
  lib/BigUnsigned.cpp)

ADD_EXECUTABLE(prs
  prs.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/ExponentiationAlgorithm.cpp
  lib/PrimitiveRootSearchAlgorithm.cpp)

ADD_EXECUTABLE(bsgs
  bsgs.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/FloorSqrtAlgorithm.cpp
  lib/PrimitiveRootSearchAlgorithm.cpp
  lib/BabyStepGiantStepAlgorithm.cpp
  lib/ExpandedEuclideanAlgorithm.cpp
  lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(elgamal
  elgamal.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/ExpandedEuclideanAlgorithm.cpp
  lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(random_prime
  lib/MillerRabinTest.cpp
  lib/BigInteger.cpp
  lib/BigUnsigned.cpp
  lib/ExponentiationAlgorithm.cpp
  lib/BlumBlumShub.cpp
  random_prime.cpp)

ADD_EXECUTABLE(dhke
	lib/BigInteger.cpp
	lib/BigUnsigned.cpp
	dhke.cpp)

