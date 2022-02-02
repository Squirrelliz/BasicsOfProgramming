//
// Created by lizka on 02.02.2022.
//

#ifndef BASICSOFPROGRAMMING2_ARRAY_H
#define BASICSOFPROGRAMMING2_ARRAY_H
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b);

size_t leftLinearSearch(const int *a, size_t n, int x);

void append(int *a, size_t *n, int value);

void deleteByPosUnsaveOrder(int *a, size_t *n, size_t position);

int isMore(const int x, const int y);

void outputArray(const int *a, size_t n);

int binarySearch(const int *a, const int n, const int value);

int compareInts(const void *a, const void *b);

void insertValue(int *const a, size_t *const n, const size_t pos, const int value);

int binarySearchCriteria(const int *a, const int n, int conditionalDigit, int (fCriteria)(int, int));

void deleteByPosSaveOrder(int *a, int *n, const size_t position);

int binarySearchEqualOrMore(const int *a, const int n, const int x);

int isNonDecreasing(const int *a, size_t n);

void insertionSort(int *a, const size_t size);


#endif //BASICSOFPROGRAMMING2_ARRAY_H
