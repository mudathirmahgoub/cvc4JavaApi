cmake_minimum_required(VERSION 3.17)
project(cvc4Api)

set(CMAKE_CXX_STANDARD 17)

include_directories("/home/mudathir/Desktop/CVC4/java/build/install/include")
link_directories("/home/mudathir/Desktop/CVC4/java/build/install/lib")

include_directories("/usr/lib/jvm/default-java/include")
include_directories("/usr/lib/jvm/default-java/include/linux")
link_directories("/usr/lib/jvm/default-java/lib")

add_executable(cvc4Api main.cpp
        cvc4_Solver.cpp
        cvc4_Solver.h
        )

add_library(cvc4JavaApi SHARED cvc4_Solver.cpp)
target_link_libraries(cvc4JavaApi cvc4)
target_link_libraries(cvc4Api cvc4)
