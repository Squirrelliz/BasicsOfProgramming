//
// Created by lizka on 14.02.2022.
//

#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include "../../algorithms/array/array.h"

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество строк
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;


matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols);

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix *m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int));

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int));

bool areTwoMatricesEqual(matrix m1, matrix m2);

bool isSquareMatrix(matrix m);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices, size_t nRows, size_t nCols);

matrix mulMatrices(matrix m1, matrix m2);

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int));

position getLeftMin(matrix m);

bool hasAllNonDescendingRows(matrix m);

int countZeroRows(matrix m);

int getMatrixNorm(matrix m);

long long getScalarProductRowAndCol(matrix m, int i, int j);

double getScalarProduct(int *a, int *b, int n);

double getVectorLength(int *a, int n);

double getCosine(int *a, int *b, int n);

#endif //MAIN_C_MATRIX_H
