//
// Created by lizka on 03.02.2022.
//

#ifndef MAIN_C_VECTOR_TESTS_H
#define MAIN_C_VECTOR_TESTS_H

#include "vector.h"


void test_createVector_zeroCapacity();

void test_createVector_notZeroCapacity();

void tests_createVector();
//________________________________________________________________//

void test_reserve_newZeroCapacity();

void test_reserve_newCapacityMoreThenSize();

void test_reserve_newCapacityLessThanSize();

void tests_reserve();
//________________________________________________________________//
void test_clear_notEmptyVector();

void tests_clear();
//________________________________________________________________//

void test_shrinkToFit_notEmptyVectorWithCapacityMoreSize();

void test_shrinkToFit_emptyVector();

void test_shrinkToFit_fullVector();

void tests_shrinkToFit();
//________________________________________________________________//

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

void test_pushBack_notEmptyNotFullVector();

void tests_pushBack();
//________________________________________________________________//

void test_popBack_notEmptyVector();

void tests_popBack();
//________________________________________________________________//

void test_atVector_notEmptyVector();

void test_atVector_requestToLastElement();

void test_atVector_requestToFirstElement();

void tests_atVector();
//________________________________________________________________//

void test_back_oneElementInVector();

void test_back_severalElements();

void tests_back();
//________________________________________________________________//

void test_front_oneElementInVector();

void test_front_severalElements();

void tests_front();
//________________________________________________________________//

void test();

#endif //MAIN_C_VECTOR_TESTS_H
