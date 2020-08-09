find_package(OpenMP REQUIRED)
add_library(yugyntrm yugyntrm.c yugyntrm.h dvyastktntrm.c dvyastktntrm.h)
target_link_libraries(yugyntrm OpenMP::OpenMP_C)

add_library(yugyntrpriksnm yugyntrm.c yugyntrm.h dvyastktntrm.c dvyastktntrm.h)
target_link_libraries(yugyntrm OpenMP::OpenMP_C)
target_compile_definitions(yugyntrpriksnm PUBLIC PRIKSNM)