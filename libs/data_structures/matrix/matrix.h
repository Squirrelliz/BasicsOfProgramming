//
// Created by lizka on 14.02.2022.
//

#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество строк
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

void badAlloc();

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix *m);

void freeMemMatrices(matrix *ms, int nMatrices);

#endif //MAIN_C_MATRIX_H
