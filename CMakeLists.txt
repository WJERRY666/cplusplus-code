cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 14)
#用于处理unicode编码问题
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_executable(test main.cpp test.h test.cpp)

#set(OpenCV_DIR "D:/opencv3.4.6/opencv/build")
#find_package(OpenCV REQUIRED)
#target_link_libraries(test ${OpenCV_LIBS})