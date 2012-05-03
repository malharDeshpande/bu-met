ADD_EXECUTABLE(ecurve ecurve.cpp)

ADD_EXECUTABLE(elgamal_key_generation
        lib/BlumBlumShub.cpp
        lib/MillerRabinTest.cpp
        lib/BigUnsigned.cpp
        lib/BigInteger.cpp
        lib/PrimitiveRootSearchAlgorithm.cpp
        lib/ExponentiationAlgorithm.cpp         
        elgamal_key_generation.cpp)

ADD_EXECUTABLE(elgamal_s1
        elgamal_s1.cpp
        lib/BigUnsigned.cpp
        lib/BigInteger.cpp
        lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(elgamal_s2
        elgamal_s2.cpp
        lib/BigUnsigned.cpp
        lib/BigInteger.cpp
        lib/ExpandedEuclideanAlgorithm.cpp)

ADD_EXECUTABLE(elgamal_v1
        elgamal_v1.cpp
        lib/BigUnsigned.cpp
        lib/BigInteger.cpp
        lib/ExponentiationAlgorithm.cpp)

ADD_EXECUTABLE(elgamal_v2
        elgamal_v2.cpp
        lib/BigUnsigned.cpp
        lib/BigInteger.cpp
        lib/ExponentiationAlgorithm.cpp)
