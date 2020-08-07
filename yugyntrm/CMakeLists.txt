add_library(yugyntrm yugyntrm.c yugyntrm.h dvyastktntrm.c dvyastktntrm.h)

add_library(yugyntrpriksnm yugyntrm.c yugyntrm.h dvyastktntrm.c dvyastktntrm.h)
target_compile_definitions(yugyntrpriksnm PUBLIC PRIKSNM)