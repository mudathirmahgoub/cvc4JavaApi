cmake_minimum_required(VERSION 3.16)
project(cvcApi)

set(CMAKE_CXX_STANDARD 17)

include_directories("install/include")
link_directories("install/lib")

find_package(JNI)

if (JNI_FOUND)
    message(STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    include_directories(${JNI_INCLUDE_DIRS})
    message(STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
    link_directories(${JNI_LIBRARIES})
endif ()

add_executable(cvcApi main.cpp
        cvc_Datatype.cpp
        cvc_DatatypeConstructorDecl.cpp
        cvc_DatatypeDecl.cpp
        cvc_Result.cpp
        cvc_Solver.cpp
        cvc_Sort.cpp
        cvc_Term.cpp)

add_library(cvcJavaApi SHARED
        cvc_Configuration.cpp
        cvc_Datatype.cpp
        cvc_DatatypeConstructorDecl.cpp
        cvc_DatatypeDecl.cpp
        cvc_Op.cpp
        cvc_Result.cpp
        cvc_Solver.cpp
        cvc_Sort.cpp
        cvc_Term.cpp)
target_link_libraries(cvcJavaApi cvc4)
target_link_libraries(cvcApi cvc4)

