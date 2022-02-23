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
//_______________________________________________________________________________________________//

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
//_______________________________________________________________________________________________//

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
//_______________________________________________________________________________________________//

void test_insertionSortRowsMatrixByRowCriteria_sortSecondOrderSquareMatrixByRowSum() {
    matrix m = createMatrixFromArray((int[]) {5, 6, 1, 2}, 2, 2);
    insertionSortRowsMatrixByRowCriteria(m, getSum);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 5, 6}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_insertionSortRowsMatrixByRowCriteria_sortOrderedSecondOrderSquareMatrixByRowSum() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 5, 6}, 2, 2);
    insertionSortRowsMatrixByRowCriteria(m, getSum);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 5, 6}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_insertionSortRowsMatrixByRowCriteria_rectangularMatrix() {
    matrix m = createMatrixFromArray((int[]) {6, 4, 1, 2, 4, 3}, 3, 2);
    insertionSortRowsMatrixByRowCriteria(m, getSum);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 4, 3, 6, 4}, 3, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_sortOrderedSecondOrderSquareMatrixByRowSum();
    test_insertionSortRowsMatrixByRowCriteria_sortSecondOrderSquareMatrixByRowSum();
    test_insertionSortRowsMatrixByRowCriteria_rectangularMatrix();
}

//_______________________________________________________________________________________________//
void test_insertionSortColsMatrixByColCriteria_sortSecondOrderSquareMatrixByColSum() {
    matrix m = createMatrixFromArray((int[]) {5, 6, 8, 2}, 2, 2);
    insertionSortColsMatrixByColCriteria(m, getSum);
    matrix expectedResult = createMatrixFromArray((int[]) {6, 5, 2, 8}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_insertionSortColsMatrixByColCriteria_sortOrderedSecondOrderSquareMatrixByColSum() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 5, 6}, 2, 2);
    insertionSortColsMatrixByColCriteria(m, getSum);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 5, 6}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_insertionSortColsMatrixByColCriteria_rectangularMatrix() {
    matrix m = createMatrixFromArray((int[]) {0, 9, 0, 3, 0, 8}, 2, 3);
    insertionSortColsMatrixByColCriteria(m, getSum);
    matrix expectedResult = createMatrixFromArray((int[]) {0, 0, 9, 3, 8, 0}, 2, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_sortSecondOrderSquareMatrixByColSum();
    test_insertionSortColsMatrixByColCriteria_sortOrderedSecondOrderSquareMatrixByColSum();
    test_insertionSortColsMatrixByColCriteria_rectangularMatrix();

}
//_______________________________________________________________________________________________//

void test_isEMatrix_notEMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 3, 1, 2, 3, 1, 2}, 3, 3);
    assert(isEMatrix(m) == false);
    freeMemMatrix(&m);
}

void test_isEMatrix_EMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 0, 1, 0, 0, 0, 1}, 3, 3);
    assert(isEMatrix(m) == true);
    freeMemMatrix(&m);
}

void tests_isEMatrix() {
    test_isEMatrix_notEMatrix();
    test_isEMatrix_EMatrix();
}
//_______________________________________________________________________________________________//

void test_isSymmetricMatrix_notSymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 3, 1, 2, 3, 1, 2}, 3, 3);
    assert(isSymmetricMatrix(m) == false);
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix_SymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 2, 0, 2, 2, 2, 1}, 3, 3);
    assert(isSymmetricMatrix(m) == true);
    freeMemMatrix(&m);
}

void tests_isSymmetricMatrix() {
    test_isSymmetricMatrix_notSymmetricMatrix();
    test_isSymmetricMatrix_SymmetricMatrix();
}
//_______________________________________________________________________________________________//

void test_transposeSquareMatrix_secondOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 1, 2}, 2, 2);
    transposeSquareMatrix(m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 2, 2}, 2, 2);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_transposeSquareMatrix_thirdOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 1, 2, 3, 1, 2, 3}, 3, 3);
    transposeSquareMatrix(m);
    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1, 2, 2, 2, 3, 3, 3}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_transposeSquareMatrix() {
    test_transposeSquareMatrix_secondOrderSquareMatrix();
    test_transposeSquareMatrix_thirdOrderSquareMatrix();
}
//_______________________________________________________________________________________________//


void test_getMinValuePos_oneMin() {
    matrix m = createMatrixFromArray((int[]) {5, 9, 3, 4}, 2, 2);
    position p = getMinValuePos(m);
    position expectedResult = {1, 0};
    assert(p.rowIndex == expectedResult.rowIndex);
    assert(p.colIndex == expectedResult.colIndex);
    freeMemMatrix(&m);
}

void test_getMinValuePos_twoMins() {
    matrix m = createMatrixFromArray((int[]) {5, 9, 3, 3}, 2, 2);
    position p = getMinValuePos(m);
    position expectedResult = {1, 0};
    assert(p.rowIndex == expectedResult.rowIndex);
    assert(p.colIndex == expectedResult.colIndex);
    freeMemMatrix(&m);
}

void tests_getMinValuePos() {
    test_getMinValuePos_oneMin();
    test_getMinValuePos_twoMins();
}
//_______________________________________________________________________________________________//

void test_getMaxValuePos_oneMax() {
    matrix m = createMatrixFromArray((int[]) {5, 9, 3, 4}, 2, 2);
    position p = getMaxValuePos(m);
    position expectedResult = {0, 1};
    assert(p.rowIndex == expectedResult.rowIndex);
    assert(p.colIndex == expectedResult.colIndex);
    freeMemMatrix(&m);
}

void test_getMaxValuePos_twoMax() {
    matrix m = createMatrixFromArray((int[]) {5, 9, 9, 3}, 2, 2);
    position p = getMaxValuePos(m);
    position expectedResult = {0, 1};
    assert(p.rowIndex == expectedResult.rowIndex);
    assert(p.colIndex == expectedResult.colIndex);
    freeMemMatrix(&m);
}

void tests_getMaxValuePos() {
    test_getMaxValuePos_oneMax();
    test_getMaxValuePos_twoMax();
}

//_______________________________________________________________________________________________//

void test_mulMatrices_twoSquareMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {3, 6, 0, 2}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 1, 1}, 2, 2);
    matrix expectedResult = createMatrixFromArray((int[]) {9, 12, 2, 2}, 2, 2);
    assert(areTwoMatricesEqual(mulMatrices(m1, m2), expectedResult));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&expectedResult);
}

void test_mulMatrices_twoRectangularMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 1, 0, 1, 2}, 2, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 0, 0, 1, 1, 1}, 3, 2);
    matrix expectedResult = createMatrixFromArray((int[]) {2, 3, 2, 3}, 2, 2);
    assert(areTwoMatricesEqual(mulMatrices(m1, m2), expectedResult));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&expectedResult);
}

void tests_mulMatrices() {
    test_mulMatrices_twoSquareMatrices();
    test_mulMatrices_twoRectangularMatrices();
}

//_______________________________________________________________________________________________//

void test_getLeftMin_oneMinInMatrix() {
    matrix m = createMatrixFromArray((int[]) {5, 1, 9, 3, 2, 0, 6, 7, 3}, 3, 3);
    position minPos = getLeftMin(m);
    assert(minPos.rowIndex == 1);
    assert(minPos.colIndex == 2);
    freeMemMatrix(&m);
}

void test_getLeftMin_twoMinInMatrix() {
    matrix m = createMatrixFromArray((int[]) {5, 1, 9, 3, 2, 0, 0, 7, 3}, 3, 3);
    position minPos = getLeftMin(m);
    assert(minPos.rowIndex == 2);
    assert(minPos.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getLeftMin_twoMinInOneCol() {
    matrix m = createMatrixFromArray((int[]) {0, 1, 9, 3, 2, 0, 0, 7, 3}, 3, 3);
    position minPos = getLeftMin(m);
    assert(minPos.rowIndex == 0);
    assert(minPos.colIndex == 0);
    freeMemMatrix(&m);
}

void tests_getLeftMin() {
    test_getLeftMin_oneMinInMatrix();
    test_getLeftMin_twoMinInMatrix();
    test_getLeftMin_twoMinInOneCol();
}

//_______________________________________________________________________________________________//
void test_hasAllNonDescendingRows_allRowsAreNonDecreasing() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 6, 4, 5, 7, 1, 2, 3}, 3, 3);
    assert(hasAllNonDescendingRows(m) == true);
    freeMemMatrix(&m);
}

void test_hasAllNonDescendingRows_aPartOfRowsAreNotNonDecreasing() {
    matrix m = createMatrixFromArray((int[]) {3, 6, 6, 4, 5, 7, 10, 2, 3}, 3, 3);
    position minPos = getLeftMin(m);
    assert(hasAllNonDescendingRows(m) == false);
    freeMemMatrix(&m);
}

void tests_hasAllNonDescendingRows() {
    test_hasAllNonDescendingRows_allRowsAreNonDecreasing();
    test_hasAllNonDescendingRows_aPartOfRowsAreNotNonDecreasing();
}

//_______________________________________________________________________________________________//
void test_countZeroRows_noZeroRows() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 1, 1, 1, 6}, 4, 2);
    assert(countZeroRows(m) == 0);
    freeMemMatrix(&m);
}

void test_countZeroRows_severalZeroRows() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 0, 0, 0, 0}, 4, 2);
    assert(countZeroRows(m) == 2);
    freeMemMatrix(&m);
}

void tests_countZeroRows() {
    test_countZeroRows_noZeroRows();
    test_countZeroRows_severalZeroRows();
}
//_______________________________________________________________________________________________//

void test_getMatrixNorm_minNegativeModuleIsNorm() {
    matrix m = createMatrixFromArray((int[]) {7, 1, -3, 9, 0, -10}, 4, 2);
    assert(getMatrixNorm(m) == 10);
    freeMemMatrix(&m);
}

void test_getMatrixNorm_maxPositiveIsNorm() {
    matrix m = createMatrixFromArray((int[]) {-7, 1, -3, 9, 0, 10}, 4, 2);
    assert(getMatrixNorm(m) == 10);
    freeMemMatrix(&m);
}

void tests_getMatrixNorm() {
    test_getMatrixNorm_minNegativeModuleIsNorm();
    test_getMatrixNorm_maxPositiveIsNorm();
}

//_______________________________________________________________________________________________//
void test_getScalarProductRowAndCol_secondOrderSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 2, 1}, 2, 2);
    assert(getScalarProductRowAndCol(m, 1, 1) == 7);
    freeMemMatrix(&m);
}

void tests_getScalarProductRowAndCol() {
    test_getScalarProductRowAndCol_secondOrderSquareMatrix();
}
//_______________________________________________________________________________________________//

void test_matrix() {
    tests_getMemMatrix();
    tests_getMemArrayOfMatrices();
    tests_freeMemMatrix();
    tests_swapRows();
    tests_swapColumns();
    tests_insertionSortRowsMatrixByRowCriteria();
    tests_insertionSortColsMatrixByColCriteria();
    tests_isEMatrix();
    tests_isSymmetricMatrix();
    tests_transposeSquareMatrix();
    tests_getMinValuePos();
    tests_getMaxValuePos();
    tests_mulMatrices();
    tests_getLeftMin();
    tests_hasAllNonDescendingRows();
    tests_countZeroRows();
    tests_getMatrixNorm();
    tests_getScalarProductRowAndCol();
}
