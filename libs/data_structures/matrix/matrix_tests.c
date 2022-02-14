//
// Created by lizka on 14.02.2022.
//

#include "matrix_tests.h"

void test_getMemMatrix_zeroElements() {
    matrix m = getMemMatrix(0, 0);
    assert(m.nRows == 0);
    assert(m.nCols == 0);
    freeMemMatrix(&m);
}

void test_getMemMatrix_moreZeroElements() {
    matrix m = getMemMatrix(3, 4);
    assert(m.nRows == 3);
    assert(m.nCols == 4);
    freeMemMatrix(&m);
}

void tests_getMemMatrix() {
    test_getMemMatrix_zeroElements();
    test_getMemMatrix_moreZeroElements();
}
//_______________________________________________________________________________________________//

void test_getMemArrayOfMatrices_notEmptyArray() {
    int size = 3;
    matrix *m = getMemArrayOfMatrices(size, 4, 2);
    assert(m->nRows == 4);
    assert(m->nCols == 2);

    freeMemMatrices(m, size);
}

void tests_getMemArrayOfMatrices() {
    test_getMemArrayOfMatrices_notEmptyArray();
}
//_______________________________________________________________________________________________//

void test_freeMemMatrix_moreZeroElements() {
    matrix m = getMemMatrix(5, 6);
    freeMemMatrix(&m);
    assert(m.nRows == 0);
    assert(m.nCols == 0);
    assert(m.values == NULL);
}

void tests_freeMemMatrix() {
    test_freeMemMatrix_moreZeroElements();
}
//_______________________________________________________________________________________________//


void test_matrix() {
    tests_getMemMatrix();
    tests_getMemArrayOfMatrices();
    tests_freeMemMatrix();
}
