//
// Created by lizka on 02.03.2022.
//

#ifndef MAIN_C_TESTS_STRING_H
#define MAIN_C_TESTS_STRING_H

#include "tasks/removeNonLetters.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

//_____________________tests_tasks_________________________________//

void test_removeNonLetters_noSpace();

void test_removeNonLetters_withSpace();

void tests_removeNonLetters();

void tests_tasks();
#endif //MAIN_C_TESTS_STRING_H
