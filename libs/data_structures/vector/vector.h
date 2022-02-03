//
// Created by lizka on 02.02.2022.
//

#ifndef MAIN_C_VECTOR_H
#define MAIN_C_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

#endif //MAIN_C_VECTOR_H
