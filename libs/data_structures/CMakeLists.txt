add_library(data_structures
        bitset/bitset.c
        ordered_array/orderedArray.c
        unordered_array/unorderedArray.c
        vector/vector.c
        vector/vector_tests.c
        vector/vectorVoid.c
        matrix/matrix.c matrix/matrix.h matrix/matrix_tests.c matrix/matrix_tests.h matrix/matrix_tasks.c matrix/matrix_tasks.h matrix/matrix_tasks_tests.c matrix/matrix_tasks_tests.h)

target_link_libraries( data_structures algorithms)