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
    insertionSortRowsMatrixByRowCriteria(m,getMax);
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



