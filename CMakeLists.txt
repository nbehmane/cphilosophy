cmake_minimum_required(VERSION 3.23)
project(cphilosophy C)

set(CMAKE_C_STANDARD 11)

include_directories(cprog_classes_complex)

add_executable(cphilosophy
        cprog_classes_complex/main.c)