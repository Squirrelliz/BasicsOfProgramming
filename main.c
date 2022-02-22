#include "libs/data_structures/matrix/matrix_tests.h"
#include "libs/data_structures/matrix/matrix_tasks_tests.h"

int main() {
    test_matrix();
    tests_matrix_tasks();
    matrix *ms = createArrayOfMatrixFromArray((int[]) {4, -2, 3, -5, 10, 10, 10, 10, -10, -10, -10, -10, 2, 2, 2, 2}, 4,
                                              2, 2);
    printMatrixWithMinNorm(ms, 4);
    return 0;
}
