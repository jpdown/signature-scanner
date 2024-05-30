cmake_minimum_required(VERSION 3.28)
project(signature-scanner)

set(CMAKE_CXX_STANDARD 23)

add_library(signature-scanner STATIC
        src/signature_scanner.cpp)

target_include_directories(signature-scanner PUBLIC "include/")