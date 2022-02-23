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
//________________________________________________________________________________________________//

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
//________________________________________________________________________________________________//

void test_sortColsByNonDecreasingMaximums_differentMinimums() {
    matrix m = createMatrixFromArray((int[]) {1, 3, 5, 8, 9, 0}, 2, 3);
    sortColsByMinElement(m);
    matrix expectedResult = createMatrixFromArray((int[]) {5, 1, 3, 0, 8, 9}, 2, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_sortColsByNonDecreasingMaximums_twoIdenticalMinimums() {
    matrix m = createMatrixFromArray((int[]) {0, 3, 5, 8, 9, 0}, 2, 3);
    sortColsByMinElement(m);
    matrix expectedResult = createMatrixFromArray((int[]) {0, 5, 3, 8, 0, 9}, 2, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_sortColsByNonDecreasingMaximums_allMinimumsAreTheSame() {
    matrix m = createMatrixFromArray((int[]) {0, 3, 9, 0, 0, 8}, 2, 3);
    sortColsByMinElement(m);
    matrix expectedResult = createMatrixFromArray((int[]) {0, 3, 9, 0, 0, 8}, 2, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_sortColsByNonDecreasingMaximums() {
    test_sortColsByNonDecreasingMaximums_differentMinimums();
    test_sortColsByNonDecreasingMaximums_twoIdenticalMinimums();
    test_sortColsByNonDecreasingMaximums_allMinimumsAreTheSame();
}
//________________________________________________________________________________________________//

void test_getSquareOfMatrixIfSymmetric_symmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 2, 0, 2, 2, 2, 1}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    matrix expectedResult = createMatrixFromArray((int[]) {9, 6, 8, 6, 8, 6, 8, 6, 9}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2, 2, 0, 2, 2, 2, 1}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 4, 2, 2, 0, 2, 2, 2, 1}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_symmetricMatrix();
    test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix();
}
//________________________________________________________________________________________________//

void test_transposeIfMatrixHasNotEqualSumOfRows_hasNoEqualSumOfRows() {
    matrix m = createMatrixFromArray((int[]) {3, 3, 3, 1, 1, 1, 7, 7, 7}, 3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    matrix expectedResult = createMatrixFromArray((int[]) {3, 1, 7, 3, 1, 7, 3, 1, 7}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSumOfRows() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1, 1, 1, 7, 7, 7}, 3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1, 1, 1, 1, 7, 7, 7}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_hasNoEqualSumOfRows();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSumOfRows();
}
//________________________________________________________________________________________________//

void test_isMutuallyInverseMatrices_mutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {2, 2, 3, 1, -1, 0, -1, 2, 1}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, -4, -3, 1, -5, -3, -1, 6, 4}, 3, 3);
    assert(isMutuallyInverseMatrices(m1, m2) == true);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_notMutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {2, 2, 3, 1, -1, 0, -1, 3, 1}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, -4, -3, 1, -5, -3, -1, 6, 4}, 3, 3);
    assert(isMutuallyInverseMatrices(m1, m2) == false);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void tests_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_mutuallyInverseMatrices();
    test_isMutuallyInverseMatrices_notMutuallyInverseMatrices();
}
//________________________________________________________________________________________________//

void test_findSumOfMaxesOfPseudoDiagonal_rectangularMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4, 1, 3, 6, 3, 3, 2, 1, 2}, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 1, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 11);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 4, 1);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 11);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_secondOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 2, 2);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 7);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal2_rectangularMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4, 1, 3, 6, 3, 3, 2, 1, 2}, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal2(m) == 20);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal2_oneRow() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 1, 4);
    assert(findSumOfMaxesOfPseudoDiagonal2(m) == 11);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal2_oneCol() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 4, 1);
    assert(findSumOfMaxesOfPseudoDiagonal2(m) == 11);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal2_secondOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4}, 2, 2);
    assert(findSumOfMaxesOfPseudoDiagonal2(m) == 7);
    freeMemMatrix(&m);
}

void tests_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_rectangularMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_secondOrderSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal2_rectangularMatrix();
    test_findSumOfMaxesOfPseudoDiagonal2_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal2_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal2_secondOrderSquareMatrix();
}
//________________________________________________________________________________________________//

void test_getMinInArea_rectangularMatrix() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6, 3, 11, 8, 9, 4, 1, 12, 2}, 3, 4);
    assert(getMinInArea(m) == 5);
    freeMemMatrix(&m);
}

void test_getMinInArea_oneRow() {
    matrix m = createMatrixFromArray((int[]) {11, 8, 9, 4, 1, 12, 2}, 1, 7);
    assert(getMinInArea(m) == 12);
    freeMemMatrix(&m);
}

void test_getMinInArea_oneCol() {
    matrix m = createMatrixFromArray((int[]) {8, 9, 4, 1, 12, 2}, 6, 1);
    assert(getMinInArea(m) == 1);
    freeMemMatrix(&m);
}

void tests_getMinInArea() {
    test_getMinInArea_rectangularMatrix();
    test_getMinInArea_oneRow();
    test_getMinInArea_oneCol();
}

//________________________________________________________________________________________________//
void test_sortByDistances_differentDistances() {
    matrix m = createMatrixFromArray((int[]) {8, 6, 1, 1, 3, 4}, 3, 2);
    sortByDistances(m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 3, 4, 8, 6}, 3, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_sortByDistances_twoIdenticalDistances() {
    matrix m = createMatrixFromArray((int[]) {8, 6, 1, 1, 6, 8}, 3, 2);
    sortByDistances(m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 8, 6, 6, 8}, 3, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_sortByDistances() {
    test_sortByDistances_differentDistances();
    test_sortByDistances_twoIdenticalDistances();
}

//________________________________________________________________________________________________//
void test_countEqClassesByRowsSum_rectangularMatrix() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2, 7, 4, 5, 4, 3, 1, 6, 8, 0}, 6, 2);
    assert(countEqClassesByRowsSum(m) == 3);
    freeMemMatrix(&m);
}

void test_countEqClassesByRowsSum_oneRow() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    assert(countEqClassesByRowsSum(m) == 1);
    freeMemMatrix(&m);
}

void test_countEqClassesByRowsSum_oneCol() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 3, 1);
    assert(countEqClassesByRowsSum(m) == 3);
    freeMemMatrix(&m);
}

void tests_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_rectangularMatrix();
    test_countEqClassesByRowsSum_oneRow();
    test_countEqClassesByRowsSum_oneCol();
}

//________________________________________________________________________________________________//
void test_getNSpecialElement_rectangularMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4, 2, 3, 6, 7, 12, 2, 1, 2}, 3, 4);
    assert(getNSpecialElement(m) == 2);
    freeMemMatrix(&m);
}

void test_getNSpecialElement_oneRow() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    assert(getNSpecialElement(m) == 3);
    freeMemMatrix(&m);
}

void test_getNSpecialElement_oneCol() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 3, 1);
    assert(getNSpecialElement(m) == 0);
    freeMemMatrix(&m);
}

void tests_getNSpecialElement() {
    test_getNSpecialElement_rectangularMatrix();
    test_getNSpecialElement_oneRow();
    test_getNSpecialElement_oneCol();
}
//________________________________________________________________________________________________//

void test_swapPenultimateRow_secondOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {8, 6, 9, 7}, 2, 2);
    swapPenultimateRow(m);
    matrix expectedResult = createMatrixFromArray((int[]) {6, 7, 9, 7}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapPenultimateRow_thirdOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 6, 0, 4, 2, 5, 0}, 3, 3);
    swapPenultimateRow(m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 3, 2, 0, 5, 2, 5, 0}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_swapPenultimateRow() {
    test_swapPenultimateRow_secondOrderSquareMatrix();
    test_swapPenultimateRow_thirdOrderSquareMatrix();
}

//________________________________________________________________________________________________//

void test_countNonDescendingRowsMatrices_noSuitableMatrices() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {2, 3, 6, 1, 5, 4, 3, 3, 2, 2, 7, 1, 1, 1, 3, 0}, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(ms, 4) == 0);
    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_severalSuitableMatrices() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {7, 1, 1, 1, 1, 6, 2, 2, 5, 4, 2, 3, 1, 3, 7, 9}, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
    freeMemMatrices(ms, 4);
}

void tests_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_noSuitableMatrices();
    test_countNonDescendingRowsMatrices_severalSuitableMatrices();
}

//________________________________________________________________________________________________//

void test_getNSpecialElement2_noSpecialElements() {
    matrix m = createMatrixFromArray((int[]) {12, 2, 13, 1}, 2, 2);
    assert(getNSpecialElement2(m) == 0);
    freeMemMatrix(&m);
}

void test_getNSpecialElement2_severalSpecialElements() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 5, 5, 4, 6, 2, 3, 8, 12, 12, 12, 2, 1, 2}, 3, 5);
    assert(getNSpecialElement2(m) == 4);
    freeMemMatrix(&m);
}

void tests_getNSpecialElement2() {
    test_getNSpecialElement2_noSpecialElements();
    test_getNSpecialElement2_severalSpecialElements();
}
//________________________________________________________________________________________________//

void test_getSpecialScalarProduct_thirdOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {2,3,6,2,1,0,1,4,5}, 3, 3);
    assert(getSpecialScalarProduct(m) == 42);
    freeMemMatrix(&m);
}

void tests_getSpecialScalarProduct(){
    test_getSpecialScalarProduct_thirdOrderSquareMatrix();
}

void tests_matrix_tasks() {
    tests_swapRowsContainingMaxAndMin();
    tests_sortRowsByNonDecreasingMaximums();
    tests_sortColsByNonDecreasingMaximums();
    tests_getSquareOfMatrixIfSymmetric();
    tests_transposeIfMatrixHasNotEqualSumOfRows();
    tests_isMutuallyInverseMatrices();
    tests_findSumOfMaxesOfPseudoDiagonal();
    tests_getMinInArea();
    tests_sortByDistances();
    tests_countEqClassesByRowsSum();
    tests_getNSpecialElement();
    tests_swapPenultimateRow();
    tests_countNonDescendingRowsMatrices();
    tests_getNSpecialElement2();
    tests_getSpecialScalarProduct();
}