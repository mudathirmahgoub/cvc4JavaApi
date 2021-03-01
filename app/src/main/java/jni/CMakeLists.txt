cmake_minimum_required(VERSION 3.16)
project(cvc4Api)

set(CMAKE_CXX_STANDARD 17)

include_directories("install/include")
link_directories("install/lib")

include_directories("/usr/lib/jvm/default-java/include")
include_directories("/usr/lib/jvm/default-java/include/linux")
link_directories("/usr/lib/jvm/default-java/lib")

add_executable(cvc4Api main.cpp
        cvc4_Solver.cpp
        cvc4_Solver.h
        cvc4_Result.cpp)

add_library(cvc4JavaApi SHARED
        cvc4_Result.cpp
        cvc4_Solver.cpp
        cvc4_Term.cpp
        )
target_link_libraries(cvc4JavaApi cvc4)
target_link_libraries(cvc4Api cvc4)
