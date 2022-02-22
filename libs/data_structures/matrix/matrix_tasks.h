//
// Created by lizka on 17.02.2022.
//

#ifndef MAIN_C_MATRIX_TASKS_H
#define MAIN_C_MATRIX_TASKS_H

#include "matrix.h"
//task 1

void swapRowsContainingMaxAndMin(matrix m);

//task 2

void sortRowsByNonDecreasingMaximums(matrix m);

//task 3

void sortColsByMinElement(matrix m);

//task 4

void getSquareOfMatrixIfSymmetric(matrix *m);

//task 5

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//task 6

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//task 7

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

long long findSumOfMaxesOfPseudoDiagonal2(matrix m);

//task 8
int getMinInArea(matrix m);

//task 9
void sortByDistances(matrix m);

//task 10

int countEqClassesByRowsSum(matrix m);

//task 11

int getNSpecialElement(matrix m);

//task 12

void swapPenultimateRow(matrix m);

//task 13

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

//task 14

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

//task 15

void printMatrixWithMinNorm(matrix *ms, int nMatrix);

#endif //MAIN_C_MATRIX_TASKS_H
