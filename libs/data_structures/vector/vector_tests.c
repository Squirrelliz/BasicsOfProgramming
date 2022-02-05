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
//_______________________________________________________________________________________________________________//

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
//_______________________________________________________________________________________________________________//

void test_atVector_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, 1) == v.data + 1);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, v.size - 1) == v.data + v.size - 1);
}

void test_atVector_requestToFirstElement() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, 0) == v.data);
}

void tests_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToFirstElement();
    test_atVector_requestToLastElement();
}
//_______________________________________________________________________________________________________________//

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(back(&v) == v.data + v.size - 1);
}

void test_back_severalElements() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(back(&v) == v.data + v.size - 1);
}

void tests_back() {
    test_back_oneElementInVector();
    test_back_severalElements();
}
//_______________________________________________________________________________________________________________//

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(front(&v) == v.data);
}

void test_front_severalElements() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(front(&v) == v.data);
}

void tests_front() {
    test_front_oneElementInVector();
    test_front_severalElements();
}
//_______________________________________________________________________________________________________________//


void test() {
    tests_pushBack();
    tests_popBack();
    tests_atVector();
    tests_back();
    tests_front();
}

