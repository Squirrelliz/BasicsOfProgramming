//
// Created by lizka on 02.02.2022.
//

#ifndef BASICSOFPROGRAMMING2_ARRAY_H
#define BASICSOFPROGRAMMING2_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void swap(int *a, int *b);

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

bool isNonDecreasing(const int *a, size_t n);

void insertionSort(int *a, const size_t size);

long long getSum(int *a, int n);

int getMax(int *a, int n);

int getMin(int *a, int n);

bool isUnique(long long *a, int n);

int max(int a, int b);

int min2(int a, int b);

float getDistance(int *a, int n);

int cmp_long_long(const void *pa, const void *pb);

int countNUnique(long long *a, int n);

int countValues(const int *a, int n, int value);

bool isEqualOrMore(const int *a, const size_t n, const int x);

bool isEqualOrLess(const int *a, const size_t n, const int x);

void inputArray(int *a, const size_t n);

int cmp_char(const void *pa, const void *pb);
#endif //BASICSOFPROGRAMMING2_ARRAY_H
