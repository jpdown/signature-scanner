cmake_minimum_required(VERSION 3.28)
project(signature_scanner)

set(CMAKE_CXX_STANDARD 23)

add_library(signature_scanner STATIC
        signature_scanner.cpp)
