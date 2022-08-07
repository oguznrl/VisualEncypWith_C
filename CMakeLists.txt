cmake_minimum_required(VERSION 3.22)
project(EncypCpp)

set(CMAKE_CXX_STANDARD 14)
find_package( OpenCV 4.2.0 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(EncypCpp main.cpp EncryptionModel.h sbox.h EncryptionModel.cpp sbox.cpp)

target_link_libraries( EncypCpp ${OpenCV_LIBS} )