add_library(yugyntrm yugyntrm.c yugyntrm.h)

add_library(yugyntrpriksnm yugyntrm.c yugyntrm.h)
target_compile_definitions(yugyntrpriksnm PUBLIC PRIKSNM)