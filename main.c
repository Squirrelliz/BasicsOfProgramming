#include "libs/data_structures/matrix/matrix_tests.h"
#include "libs/data_structures/matrix/matrix_tasks_tests.h"

int main() {
    test_matrix();
    tests_matrix_tasks();
    //matrix m1 = createMatrixFromArray((int[]) {1, 2, 1, 0, 1, 2}, 2, 3);
    //matrix m2 = createMatrixFromArray((int[]) {1, 0, 0, 1, 1, 1}, 3, 2);
   // matrix m = createMatrixFromArray((int[]) {1, 2, 2, 2, 0, 2, 2, 2, 1}, 3, 3);
   // getSquareOfMatrixIfSymmetric(&m);
   // matrix expectedResult = createMatrixFromArray((int[]) {9, 6, 8, 6, 8, 6, 8, 6, 9}, 3, 3);
   // outputMatrix(m);
   // outputMatrix(expectedResult);
    return 0;
}
