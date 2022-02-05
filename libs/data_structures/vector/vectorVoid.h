//
// Created by lizka on 05.02.2022.
//

#ifndef MAIN_C_VECTORVOID_H
#define MAIN_C_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

void _badAlloc();

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора

    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

bool isEmptyV(vectorVoid *v);

bool isFullV(vectorVoid *v);

void getVectorValueV(vectorVoid *v, size_t index, void *destination);

void setVectorValueV(vectorVoid *v, size_t index, void *source);

void popBackV(vectorVoid *v);

void pushBackV(vectorVoid *v, void *source);

#endif //MAIN_C_VECTORVOID_H
