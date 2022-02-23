//
// Created by lizka on 14.02.2022.
//

#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; ++i) {
        ms[i] = getMemMatrix(nRows, nCols);
    }
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }
    free(m->values);
    m->nRows = 0;
    m->nCols = 0;
    m->values = NULL;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(&ms[i]);
    }
    free(ms);
}

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; ++i) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m1.nCols; ++j) {
            if (m1.values[i][j] != m2.values[i][j])
                return false;
        }
    }
    return true;
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *auxiliaryArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        auxiliaryArray[i] = criteria(m.values[i], m.nCols);
    }

    for (size_t i = 1; i < m.nRows; i++) {
        int t = auxiliaryArray[i];
        int *f = m.values[i];
        int j = i;
        while (j > 0 && auxiliaryArray[j - 1] > t) {
            auxiliaryArray[j] = auxiliaryArray[j - 1];
            m.values[j] = m.values[j - 1];
            j--;
        }
        auxiliaryArray[j] = t;
        m.values[j] = f;
    }
    free(auxiliaryArray);
}


void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *auxiliaryArray = (int *) malloc(sizeof(int) * m.nCols);
    int *basketForCurrentCol = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j) {
            basketForCurrentCol[j] = m.values[j][i];
        }
        auxiliaryArray[i] = criteria(basketForCurrentCol, m.nRows);
    }
    for (size_t i = 1; i < m.nCols; i++) {
        int t = auxiliaryArray[i];
        for (int j = 0; j < m.nRows; ++j) {
            basketForCurrentCol[j] = m.values[j][i];
        }
        int j = i;
        while (j > 0 && auxiliaryArray[j - 1] > t) {
            auxiliaryArray[j] = auxiliaryArray[j - 1];
            for (int k = 0; k < m.nRows; ++k) {
                m.values[k][j] = m.values[k][j - 1];
            }
            j--;
        }
        auxiliaryArray[j] = t;
        for (int l = 0; l < m.nRows; ++l) {
            m.values[l][j] = basketForCurrentCol[l];
        }
    }
    free(auxiliaryArray);
    free(basketForCurrentCol);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i != j && m.values[i][j] != 0 || i == j && m.values[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 1; j + i < m.nRows; ++j) {
            int k = j + i;
            if (m.values[k][i] != m.values[i][k])
                return false;
        }
    }
    return true;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 1; j + i < m.nRows; ++j) {
            int k = j + i;
            swap(&m.values[k][i], &m.values[i][k]);
        }
    }
}

position getMinValuePos(matrix m) {
    position min = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            }
        }
    }
    return min;
}

position getMaxValuePos(matrix m) {
    position max = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] > m.values[max.rowIndex][max.colIndex]) {
                max.rowIndex = i;
                max.colIndex = j;
            }
        }
    }
    return max;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "the number of columns of the first matrix is not equal to the number of rows of the second");
        exit(1);
    }
    matrix resultMatrix = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            resultMatrix.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; ++k) {
                resultMatrix.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }

    return resultMatrix;
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *auxiliaryArray = (float *) malloc(sizeof(float) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        auxiliaryArray[i] = criteria(m.values[i], m.nCols);
    }

    for (size_t i = 1; i < m.nRows; i++) {
        float t = auxiliaryArray[i];
        int *f = m.values[i];
        int j = i;
        while (j > 0 && auxiliaryArray[j - 1] > t) {
            auxiliaryArray[j] = auxiliaryArray[j - 1];
            m.values[j] = m.values[j - 1];
            j--;
        }
        auxiliaryArray[j] = t;
        m.values[j] = f;
    }
    free(auxiliaryArray);
}

position getLeftMin(matrix m) {
    position min = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            } else if (m.values[i][j] == m.values[min.rowIndex][min.colIndex] && j < min.colIndex) {
                min.rowIndex = i;
                min.colIndex = j;
            }
        }
    }
    return min;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        if (!isNonDecreasing(m.values[i], m.nCols))
            return false;
    }
    return true;
}

int countZeroRows(matrix m) {
    int nZeroRows = 0;
    for (int i = 0; i < m.nRows; ++i) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            nZeroRows++;
    }

    return nZeroRows;
}

int getMatrixNorm(matrix m) {
    int absMax = abs(m.values[0][0]);
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int currentEl = abs(m.values[i][j]);
            if (currentEl > absMax)
                absMax = currentEl;
        }
    }

    return  absMax;
}

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long product = 0;
    for (int k = 0; k < m.nCols; ++k) {
        product += m.values[i][k] * m.values[k][j];
    }

    return product;
}






