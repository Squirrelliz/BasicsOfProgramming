//
// Created by lizka on 02.02.2022.
//

#include "vector.h"

void badAlloc() {
    fprintf(stderr, "bad alloc ");
    exit(1);
}

vector createVector(size_t n) {
    vector v = {malloc(sizeof(int) * n), 0, n};
    if (v.data == NULL) {
        badAlloc();
    } else
        return v;
}

void reserve(vector *v, size_t newCapacity) {
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    v->capacity = newCapacity;
    v->size = newCapacity < v->size ? newCapacity : v->size;
    if (newCapacity == 0)
        return;
    if (v->data == NULL) {
        badAlloc();
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    reserve(v, 0);
}

