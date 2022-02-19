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

void tests_matrix_tasks();

#endif //MAIN_C_MATRIX_TASKS_TESTS_H
