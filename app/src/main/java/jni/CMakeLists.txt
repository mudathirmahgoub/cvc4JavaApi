cmake_minimum_required(VERSION 3.16)
project(cvc4Api)

set(CMAKE_CXX_STANDARD 17)

include_directories("install/include")
link_directories("install/lib")

find_package(JNI)

if(JNI_FOUND)
    message(STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    include_directories(${JNI_INCLUDE_DIRS})
    message(STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
    link_directories(${JNI_LIBRARIES})
endif()

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

