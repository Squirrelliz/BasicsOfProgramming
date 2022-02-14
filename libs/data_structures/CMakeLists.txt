add_library(data_structures
        bitset/bitset.c
        ordered_array/orderedArray.c
        unordered_array/unorderedArray.c
        vector/vector.c
        vector/vector_tests.c
        vector/vectorVoid.c
        matrix/matrix.c matrix/matrix.h)

target_link_libraries(data_structures algorithms)