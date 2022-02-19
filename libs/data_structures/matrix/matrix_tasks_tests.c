//
// Created by lizka on 17.02.2022.
//

#include "matrix_tasks_tests.h"

void test_swapRowsContainingMaxAndMin_oneMinOneMaxInDifferentRows() {
    matrix m = createMatrixFromArray((int[]) {2, 5, 7, 3, 0, 6, 9, 4, 1}, 3, 3);
    swapRowsContainingMaxAndMin(m);
    matrix expectedResult = createMatrixFromArray((int[]) {2, 5, 7, 9, 4, 1, 3, 0, 6}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapRowsContainingMaxAndMin_severalMinimumsAndMaximumsInDifferentRows() {
    matrix m = createMatrixFromArray((int[]) {9, 5, 7, 3, 0, 6, 9, 0, 1}, 3, 3);
    swapRowsContainingMaxAndMin(m);
    matrix expectedResult = createMatrixFromArray((int[]) {3, 0, 6, 9, 5, 7, 9, 0, 1}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_swapRowsContainingMaxAndMin() {
    test_swapRowsContainingMaxAndMin_oneMinOneMaxInDifferentRows();
    test_swapRowsContainingMaxAndMin_severalMinimumsAndMaximumsInDifferentRows();
}

void test_sortRowsByNonDecreasingMaximums_differentMaximums() {
    matrix m = createMatrixFromArray((int[]) {9, 0, 5, 3, 1, 0, 1, 4, 2}, 3, 3);
    sortRowsByNonDecreasingMaximums(m);
    matrix expectedResult = createMatrixFromArray((int[]) {3, 1, 0, 1, 4, 2, 9, 0, 5}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_sortRowsByNonDecreasingMaximums_twoIdenticalMaximums() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2, 3, 1, 0, 4, 0, 0}, 3, 3);
    sortRowsByNonDecreasingMaximums(m);
    matrix expectedResult = createMatrixFromArray((int[]) {3, 1, 0, 1, 4, 2, 4, 0, 0}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_sortRowsByNonDecreasingMaximums_allMaximumsAreTheSame() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2, 4, 1, 0, 4, 0, 0}, 3, 3);
    sortRowsByNonDecreasingMaximums(m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 4, 2, 4, 1, 0, 4, 0, 0}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_sortRowsByNonDecreasingMaximums() {
    test_sortRowsByNonDecreasingMaximums_differentMaximums();
    test_sortRowsByNonDecreasingMaximums_twoIdenticalMaximums();
    test_sortRowsByNonDecreasingMaximums_allMaximumsAreTheSame();

}

void tests_matrix_tasks() {
    tests_swapRowsContainingMaxAndMin();
    tests_sortRowsByNonDecreasingMaximums();
}