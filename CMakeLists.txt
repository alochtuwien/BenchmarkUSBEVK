cmake_minimum_required(VERSION 3.24)
project(BenchmarkUSB)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_CXX_STANDARD 14)

find_package(MetavisionSDK COMPONENTS core driver ui REQUIRED)
find_package(OpenCV COMPONENTS highgui REQUIRED)

add_executable(BenchmarkUSB main.cpp)
target_link_libraries(BenchmarkUSB MetavisionSDK::core MetavisionSDK::driver MetavisionSDK::ui opencv_highgui)


