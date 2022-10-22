cmake_minimum_required(VERSION 3.0.0)
project(integral-calculator
  VERSION 1.0
  DESCRIPTION "Simple calculator for (improper) integrals"
  LANGUAGES CXX)

add_executable(integral
  src/integral/calculate.h
  src/integral/calculate.cpp
  src/integral/function.h 
  src/integral/function.cpp
  src/integral/main.cpp)

add_executable(rewrite-function
  src/rewrite-function/main.cpp)

target_compile_features(integral PRIVATE cxx_std_11)
target_compile_options(integral PRIVATE -Wall
                        -Wextra -Wpedantic 
                        -Werror -O3 -mfpmath=sse)
