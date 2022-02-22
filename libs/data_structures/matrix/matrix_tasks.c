//
// Created by lizka on 17.02.2022.
//

#include "matrix_tasks.h"

//task 1

void swapRowsContainingMaxAndMin(matrix m) {
    position minPos, maxPos;
    minPos = getMinValuePos(m);
    maxPos = getMaxValuePos(m);

    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

//task 2

void sortRowsByNonDecreasingMaximums(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//task 3

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

//task 4

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

//task 5
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long *arraySumsOfRowElements = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        arraySumsOfRowElements[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(arraySumsOfRowElements, m.nRows))
        transposeSquareMatrix(m);
}

//task 6

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

//task 7

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    position start = {m.nRows - 1, -1};//{0,0}
    int s = 0;//s=3
    while (start.rowIndex >= 0) {
        while (start.colIndex < m.nCols - 1) {
            start.colIndex++;
            if (start.colIndex == start.rowIndex)
                continue;
            int maximum = m.values[start.rowIndex][start.colIndex];
            for (int j = start.rowIndex, k = start.colIndex; j >= 0 && k >= 0; --j, --k) {
                maximum = max(maximum, m.values[j][k]);
            }
            s += maximum;
        }
        start.rowIndex--;
        start.colIndex--;
    }
    return s;
}

long long findSumOfMaxesOfPseudoDiagonal2(matrix m) {
    int n_diagonals = m.nRows + m.nCols - 1;
    int *arrayOfMaximums = (int *) malloc(sizeof(int) * n_diagonals);
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int diagonal_index = j - i - 1 + m.nRows;
            if (j == 0 || i == 0)
                arrayOfMaximums[diagonal_index] = m.values[i][j];
            else
                arrayOfMaximums[diagonal_index] = max(arrayOfMaximums[diagonal_index], m.values[i][j]);

        }
    }

    swap(&arrayOfMaximums[0 - 1 + m.nRows], &arrayOfMaximums[0]);
    long long s = getSum(arrayOfMaximums + 1, n_diagonals - 1);
    free(arrayOfMaximums);
    return s;
}

//task 8
int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);
    int min = m.values[maxPos.rowIndex][maxPos.colIndex];
    int rightElementColIndex = maxPos.colIndex;
    int length = 1;
    for (int i = maxPos.rowIndex; i >= 0; --i) {
        for (int j = rightElementColIndex; (j - rightElementColIndex) < length && j < m.nCols; ++j) {
            min = min2(min, m.values[i][j]);
        }
        length += 2;
    }
    return min;
}

//task 9
void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

//task 10

int countEqClassesByRowsSum(matrix m) {
    long long *rowSumArray = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        rowSumArray[i] = getSum(m.values[i], m.nCols);
    }

    return countNUnique(rowSumArray, m.nRows);
}

//task 11
int getNSpecialElement(matrix m) {
    int *maxPosInCol = (int *) malloc(sizeof(int) * m.nCols);
    int *maxOfCols = (int *) malloc(sizeof(int) * m.nCols);
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i == 0) {
                maxOfCols[j] = m.values[i][j];
                maxPosInCol[j] = 0;
            } else if (maxOfCols[j] < m.values[i][j]) {
                maxOfCols[j] = m.values[i][j];
                maxPosInCol[j] = i;
            }
        }
    }
    int countSpecialEl = m.nCols;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (maxPosInCol[j] == i)
                continue;
            maxOfCols[j] -= m.values[i][j];
            if (maxOfCols[j] <= 0)
                countSpecialEl--;
        }
    }

    free(maxPosInCol);
    free(maxOfCols);
    return countSpecialEl;
}

//task 12
void swapPenultimateRow(matrix m) {
    position colOfFirstMin = getLeftMin(m);
    for (int j = 0; j < m.nCols; ++j) {
        m.values[m.nRows - 2][j] = m.values[j][colOfFirstMin.colIndex];
    }
}










