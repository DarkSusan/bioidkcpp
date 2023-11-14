cmake_minimum_required(VERSION 3.0)
project(biocpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(biocpp main.cpp FastaN.cpp FastaN.h biocpp.h cmake-build-debug/test.cpp test.cpp test.cpp FastaQ.cpp FastaQ.h RecordN.cpp RecordN.h RecordQ.cpp RecordQ.h)
