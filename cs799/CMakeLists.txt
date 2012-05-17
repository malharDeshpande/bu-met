PROJECT(CS799)

FILE(GLOB cs799_SOURCES lib/*.cpp)
FILE(GLOB cs799_HEADERS lib/*.h)

ADD_EXECUTABLE(ecurve ecurve.cpp)

ADD_EXECUTABLE(elgamal_key_generation
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_key_generation.cpp)

ADD_EXECUTABLE(elgamal_sign    
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_sign.cpp)        

ADD_EXECUTABLE(elgamal_verify
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_verify.cpp)        

ADD_EXECUTABLE(elgamal_s1
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_s1.cpp)

ADD_EXECUTABLE(elgamal_s2
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_s2.cpp)

ADD_EXECUTABLE(elgamal_v1
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_v1.cpp)

ADD_EXECUTABLE(elgamal_v2
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_v2.cpp)

ADD_EXECUTABLE(elgamal_exchange
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_exchange.cpp)

ADD_EXECUTABLE(elgamal_exchange_and_break
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_exchange_and_break.cpp)

ADD_EXECUTABLE(elgamal
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal.cpp)

ADD_EXECUTABLE(elgamal_trials
        ${cs799_SOURCES}
        ${cs799_HEADERS}
        elgamal_trials.cpp)
