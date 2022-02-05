//
// Created by lizka on 02.02.2022.
//

#ifndef MAIN_C_VECTOR_H
#define MAIN_C_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
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

bool isEmpty(vector *v);

bool isFull(vector *v);

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);

int *atVector(vector *v, size_t index);

int *back(vector *v);

int *front(vector *v);

#endif //MAIN_C_VECTOR_H
