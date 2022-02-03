//
// Created by lizka on 03.02.2022.
//

#include "vector_tests.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(getVectorValue(&v, 0) == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBack_fullVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(getVectorValue(&v, 1) == 2);
    assert(v.size == 2);
    assert(v.capacity == 2);
}

void test_pushBack_notEmptyNotFullVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    assert(getVectorValue(&v, 3) == 4);
    assert(v.size == 4);
    assert(v.capacity == 4);
}

void tests_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_notEmptyNotFullVector();
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void tests_popBack() {
    test_popBack_notEmptyVector();
}

void test() {
    tests_pushBack();
    tests_popBack();
}