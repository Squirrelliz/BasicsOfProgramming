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

void test_insertionSortRowsMatrixByRowCriteria_sortThirdOrderSquareMatrixByRowSum();

void tests_insertionSortRowsMatrixByRowCriteria();

//_______________________________________________________________________________________________//
void test_insertionSortColsMatrixByColCriteria_sortSecondOrderSquareMatrixByColSum();

void test_insertionSortColsMatrixByColCriteria_sortOrderedSecondOrderSquareMatrixByColSum();

void test_insertionSortColsMatrixByColCriteria_sortThirdOrderSquareMatrixByColSum();

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

void test_matrix();


#endif //MAIN_C_MATRIX_TESTS_H
