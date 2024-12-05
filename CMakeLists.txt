cmake_minimum_required(VERSION 3.28.3)
project(opencvv)
find_package( OpenCV REQUIRED )
set(CMAKE_CXX_STANDARD 20)
include_directories(${OpenCV_INCLUDE_DIRS})
# add_executable(opencvv main.cpp Steganography.cpp )
add_executable(opencvv main.cpp Steganography.cpp ImageInfo.cpp )
target_link_libraries( opencvv ${OpenCV_LIBS} )

# Steganography.cpp ImageInfo.h ImageInfo.cu ImageInfo.cpp

