cmake_minimum_required(VERSION 3.10)

project(yugyntrm)

add_subdirectory(yugyntrm)

add_executable(priksnm priksnm/priksnm.c)
target_link_libraries(priksnm yugyntrpriksnm)
target_include_directories(priksnm PUBLIC yugyntrm)
target_compile_definitions(priksnm PUBLIC PRIKSNM)