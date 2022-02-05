//
// Created by lizka on 03.02.2022.
//

#include "vector_tests.h"

void test_createVector_zeroCapacity() {
    vector v = createVector(0);
    assert(v.size == 0);
    assert(v.capacity == 0);
    deleteVector(&v);
}

void test_createVector_notZeroCapacity() {
    vector v = createVector(3);
    assert(v.size == 0);
    assert(v.capacity == 3);
    deleteVector(&v);
}

void tests_createVector() {
    test_createVector_zeroCapacity();
    test_createVector_notZeroCapacity();
}
//_______________________________________________________________________________________________________________//

void test_reserve_newZeroCapacity() {
    vector v = createVector(3);
    reserve(&v, 0);
    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);
    deleteVector(&v);
}

void test_reserve_newCapacityMoreThenSize() {
    vector v = createVector(1);
    pushBack(&v, 2);
    reserve(&v, 3);
    assert(v.capacity == 3);
    assert(v.size == 1);
    deleteVector(&v);
}

void test_reserve_newCapacityLessThanSize() {
    vector v = createVector(2);
    pushBack(&v, 2);
    pushBack(&v, 3);
    reserve(&v, 1);
    assert(v.capacity == 1);
    assert(v.size == 1);
    deleteVector(&v);
}

void tests_reserve() {
    test_reserve_newZeroCapacity();
    test_reserve_newCapacityMoreThenSize();
    test_reserve_newCapacityLessThanSize();
}
//_______________________________________________________________________________________________________________//

void test_clear_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 2);
    pushBack(&v, 3);
    clear(&v);
    assert(v.size == 0);
    assert(v.capacity == 2);
    deleteVector(&v);
}

void tests_clear() {
    test_clear_notEmptyVector();
}
//_______________________________________________________________________________________________________________//

void test_shrinkToFit_notEmptyVectorWithCapacityMoreSize() {
    vector v = createVector(5);
    pushBack(&v, 2);
    pushBack(&v, 3);
    shrinkToFit(&v);
    assert(isFull(&v));
    deleteVector(&v);
}

void test_shrinkToFit_emptyVector() {
    vector v = createVector(5);
    shrinkToFit(&v);
    assert(isFull(&v));
    deleteVector(&v);
}

void test_shrinkToFit_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 3);
    shrinkToFit(&v);
    assert(isFull(&v));
    deleteVector(&v);
}

void tests_shrinkToFit() {
    test_shrinkToFit_notEmptyVectorWithCapacityMoreSize();
    test_shrinkToFit_emptyVector();
    test_shrinkToFit_fullVector();
}
//_______________________________________________________________________________________________________________//

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(getVectorValue(&v, 0) == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(getVectorValue(&v, 1) == 2);
    assert(v.size == 2);
    assert(v.capacity == 2);
    deleteVector(&v);
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
    deleteVector(&v);
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
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
    deleteVector(&v);
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
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, v.size - 1) == v.data + v.size - 1);
    deleteVector(&v);
}

void test_atVector_requestToFirstElement() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, 0) == v.data);
    deleteVector(&v);
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
    deleteVector(&v);
}

void test_back_severalElements() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(back(&v) == v.data + v.size - 1);
    deleteVector(&v);
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
    deleteVector(&v);
}

void test_front_severalElements() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(front(&v) == v.data);
    deleteVector(&v);
}

void tests_front() {
    test_front_oneElementInVector();
    test_front_severalElements();
}
//_______________________________________________________________________________________________________________//


void test() {
    tests_createVector();
    tests_reserve();
    tests_clear();
    tests_shrinkToFit();
    tests_pushBack();
    tests_popBack();
    tests_atVector();
    tests_back();
    tests_front();
}

