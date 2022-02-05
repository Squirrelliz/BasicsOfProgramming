//
// Created by lizka on 05.02.2022.
//

#include "vectorVoid.h"
vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid v = {malloc(sizeof(baseTypeSize * n)),0,n,baseTypeSize};
    if (v.data == NULL) {
        badAlloc_();
    } else
        return v;
}

void reserveV(vectorVoid *v, size_t newCapacity){
    v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    v->capacity = newCapacity;
    v->size = newCapacity < v->size ? newCapacity : v->size;
    if (newCapacity == 0)
        return;
    if (v->data == NULL) {
        badAlloc_();
    }
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v, v->size);
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    reserveV(v, 0);
}

