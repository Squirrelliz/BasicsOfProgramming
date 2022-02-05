//
// Created by lizka on 05.02.2022.
//

#include "vectorVoid.h"

void badAlloc_() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v = {malloc(sizeof(baseTypeSize * n)), 0, n, baseTypeSize};
    if (v.data == NULL) {
        badAlloc_();
    } else
        return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    v->capacity = newCapacity;
    v->size = newCapacity < v->size ? newCapacity : v->size;
    if (newCapacity == 0)
        return;
    if (v->data == NULL) {
        badAlloc_();
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    reserveV(v, 0);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "there's nothing to delete here");
        exit(1);
    } else
        v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v) && v->capacity != 0)
        reserveV(v, v->capacity * 2);
    else if (v->capacity == 0)
        reserveV(v, 1);
    setVectorValueV(v, v->size, source);
    v->size++;
}
