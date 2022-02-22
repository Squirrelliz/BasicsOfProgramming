//
// Created by lizka on 14.02.2022.
//

#ifndef MAIN_C_MATRIX_TESTS_H
#define MAIN_C_MATRIX_TESTS_H

#include "matrix.h"
#include <assert.h>

void test_getMemMatrix_zeroElements();

void test_getMemMatrix_moreZeroElements();

void tests_getMemMatrix();
//_______________________________________________________________________________________________//

void test_getMemArrayOfMatrices_notEmptyArray();

void tests_getMemArrayOfMatrices();
//_______________________________________________________________________________________________//

void test_freeMemMatrix_moreZeroElements();

void tests_freeMemMatrix();
//_______________________________________________________________________________________________//

void test_swapRows_oneCol();

void test_swapRows_secondOrderSquareMatrix();

void test_swapRows_rectangularMatrixWithSeveralRows();

void tests_swapRows();
//_______________________________________________________________________________________________//

void test_swapColumns_oneRow();

void test_swapColumns_secondOrderSquareMatrix();

void test_swapColumns_rectangularMatrixWithSeveralColumns();

void tests_swapColumns();

//_______________________________________________________________________________________________//
void test_insertionSortRowsMatrixByRowCriteria_sortSecondOrderSquareMatrixByRowSum();

void test_insertionSortRowsMatrixByRowCriteria_sortOrderedSecondOrderSquareMatrixByRowSum();

void test_insertionSortRowsMatrixByRowCriteria_rectangularMatrix();

void tests_insertionSortRowsMatrixByRowCriteria();

//_______________________________________________________________________________________________//
void test_insertionSortColsMatrixByColCriteria_sortSecondOrderSquareMatrixByColSum();

void test_insertionSortColsMatrixByColCriteria_sortOrderedSecondOrderSquareMatrixByColSum();

void test_insertionSortColsMatrixByColCriteria_rectangularMatrix();

void tests_insertionSortColsMatrixByColCriteria();
//_______________________________________________________________________________________________//

void test_isEMatrix_notEMatrix();

void test_isEMatrix_EMatrix();

void tests_isEMatrix();
//_______________________________________________________________________________________________//

void test_isSymmetricMatrix_notSymmetricMatrix();

void test_isSymmetricMatrix_SymmetricMatrix();

void tests_isSymmetricMatrix();
//_______________________________________________________________________________________________//

void test_transposeSquareMatrix_secondOrderSquareMatrix();

void test_transposeSquareMatrix_thirdOrderSquareMatrix();

void tests_transposeSquareMatrix();

//_______________________________________________________________________________________________//
void test_getMinValuePos_oneMin();

void test_getMinValuePos_twoMins();

void tests_getMinValuePos();
//_______________________________________________________________________________________________//

void test_getMaxValuePos_oneMax();

void test_getMaxValuePos_twoMax();

void tests_getMaxValuePos();
//_______________________________________________________________________________________________//

void test_mulMatrices_twoSquareMatrices();

void test_mulMatrices_twoRectangularMatrices();

void tests_mulMatrices();

//_______________________________________________________________________________________________//

void test_getLeftMin_oneMinInMatrix();

void test_getLeftMin_twoMinInMatrix();

void test_getLeftMin_twoMinInOneCol();

void tests_getLeftMin();

//_______________________________________________________________________________________________//

void test_swapPenultimateRow_secondOrderSquareMatrix();

void test_swapPenultimateRow_thirdOrderSquareMatrix();

void tests_swapPenultimateRow();
//_______________________________________________________________________________________________//

void tests_hasAllNonDescendingRows();

void test_hasAllNonDescendingRows_allRowsAreNonDecreasing();

void test_hasAllNonDescendingRows_aPartOfRowsAreNotNonDecreasing();
//_______________________________________________________________________________________________//
void test_matrix();


#endif //MAIN_C_MATRIX_TESTS_H
