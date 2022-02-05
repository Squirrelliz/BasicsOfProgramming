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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v) && v->capacity != 0)
        reserve(v, v->capacity * 2);
    else if (v->capacity == 0)
        reserve(v, 1);
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "there's nothing to delete here");
        exit(1);
    } else
        v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index < v->size)
        return v->data + index;
    else {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }
}

int *back(vector *v) {
    return atVector(v, v->size - 1);
}

int *front(vector *v) {
    return atVector(v, 0);
}

