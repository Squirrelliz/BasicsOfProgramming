//
// Created by lizka on 14.02.2022.
//

#include "matrix_tests.h"

void test_getMemMatrix_zeroElements() {
    matrix m = getMemMatrix(0, 0);
    assert(m.nRows == 0);
    assert(m.nCols == 0);
    freeMemMatrix(&m);
}

void test_getMemMatrix_moreZeroElements() {
    matrix m = getMemMatrix(3, 4);
    assert(m.nRows == 3);
    assert(m.nCols == 4);
    freeMemMatrix(&m);
}

void tests_getMemMatrix() {
    test_getMemMatrix_zeroElements();
    test_getMemMatrix_moreZeroElements();
}
//_______________________________________________________________________________________________//

void test_getMemArrayOfMatrices_notEmptyArray() {
    int size = 3;
    matrix *m = getMemArrayOfMatrices(size, 4, 2);
    assert(m->nRows == 4);
    assert(m->nCols == 2);

    freeMemMatrices(m, size);
}

void tests_getMemArrayOfMatrices() {
    test_getMemArrayOfMatrices_notEmptyArray();
}
//_______________________________________________________________________________________________//

void test_freeMemMatrix_moreZeroElements() {
    matrix m = getMemMatrix(5, 6);
    freeMemMatrix(&m);
    assert(m.nRows == 0);
    assert(m.nCols == 0);
    assert(m.values == NULL);
}

void tests_freeMemMatrix() {
    test_freeMemMatrix_moreZeroElements();
}

void test_swapRows_oneCol() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 4, 1);
    swapRows(m, 0, 3);
    matrix expectedResult = createMatrixFromArray((int[]) {4, 2, 3, 1}, 4, 1);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapRows_secondOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    swapRows(m, 0, 1);
    matrix expectedResult = createMatrixFromArray((int[]) {3, 4, 1, 2}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapRows_rectangularMatrixWithSeveralRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 3, 2);
    swapRows(m, 1, 2);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 5, 6, 3, 4}, 3, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_swapRows() {
    test_swapRows_oneCol();
    test_swapRows_secondOrderSquareMatrix();
     test_swapRows_rectangularMatrixWithSeveralRows();
}

void test_swapColumns_oneRow() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 1, 4);
    swapColumns(m, 0, 1);
    matrix expectedResult = createMatrixFromArray((int[]) {2, 1, 3, 4}, 1, 4);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapColumns_secondOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    swapColumns(m, 0, 1);
    matrix expectedResult = createMatrixFromArray((int[]) {2, 1, 4, 3}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapColumns_rectangularMatrixWithSeveralColumns() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 2, 4);
    swapColumns(m, 0, 2);
    matrix expectedResult = createMatrixFromArray((int[]) {3, 2, 1, 4, 7, 6, 5, 8}, 2, 4);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_swapColumns() {
    test_swapColumns_oneRow();
   test_swapColumns_secondOrderSquareMatrix();
   test_swapColumns_rectangularMatrixWithSeveralColumns();
}

void test_matrix() {
    tests_getMemMatrix();
    tests_getMemArrayOfMatrices();
    tests_freeMemMatrix();
    tests_swapRows();
    tests_swapColumns();
}
//_______________________________________________________________________________________________//



