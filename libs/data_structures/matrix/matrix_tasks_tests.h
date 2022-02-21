//
// Created by lizka on 17.02.2022.
//

#ifndef MAIN_C_MATRIX_TASKS_TESTS_H
#define MAIN_C_MATRIX_TASKS_TESTS_H

#include "matrix_tasks.h"

void test_swapRowsContainingMaxAndMin_oneMinOneMaxInDifferentRows();

void test_swapRowsContainingMaxAndMin_severalMinimumsAndMaximumsInDifferentRows();

void tests_swapRowsContainingMaxAndMin();
//_________________________________________________________________________________//

void test_sortRowsByNonDecreasingMaximums_differentMaximums();

void test_sortRowsByNonDecreasingMaximums_twoIdenticalMaximums();

void test_sortRowsByNonDecreasingMaximums_allMaximumsAreTheSame();

void tests_sortRowsByNonDecreasingMaximums();
//_________________________________________________________________________________//

void test_sortColsByNonDecreasingMaximums_differentMinimums();

void test_sortColsByNonDecreasingMaximums_twoIdenticalMinimums();

void test_sortColsByNonDecreasingMaximums_allMinimumsAreTheSame();

void tests_sortColsByNonDecreasingMaximums();

//_________________________________________________________________________________//

void test_getSquareOfMatrixIfSymmetric_symmetricMatrix();

void test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix();

void tests_getSquareOfMatrixIfSymmetric();

//_________________________________________________________________________________//

void test_transposeIfMatrixHasNotEqualSumOfRows_hasNoEqualSumOfRows();

void test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSumOfRows();

void tests_transposeIfMatrixHasNotEqualSumOfRows();
//_________________________________________________________________________________//

void test_isMutuallyInverseMatrices_mutuallyInverseMatrices();

void test_isMutuallyInverseMatrices_notMutuallyInverseMatrices();

void tests_isMutuallyInverseMatrices();

void test_findSumOfMaxesOfPseudoDiagonal_rectangularMatrix();

void test_findSumOfMaxesOfPseudoDiagonal_oneRow();

void test_findSumOfMaxesOfPseudoDiagonal_oneCol();

void test_findSumOfMaxesOfPseudoDiagonal_secondOrderSquareMatrix();

void tests_findSumOfMaxesOfPseudoDiagonal();

//_________________________________________________________________________________//
void tests_getMinInArea();

void test_getMinInArea_rectangularMatrix();

void test_getMinInArea_oneRow();

void test_getMinInArea_oneCol();

//_________________________________________________________________________________//

void test_sortByDistances_differentDistances();

void test_sortByDistances_twoIdenticalDistances();

void tests_sortByDistances();

//_________________________________________________________________________________//

void tests_countEqClassesByRowsSum();

void test_countEqClassesByRowsSum_rectangularMatrix();

void test_countEqClassesByRowsSum_oneRow();

void test_countEqClassesByRowsSum_oneCol();

//_________________________________________________________________________________//
void tests_matrix_tasks();

#endif //MAIN_C_MATRIX_TASKS_TESTS_H
