//
// Created by lizka on 02.03.2022.
//

#ifndef MAIN_C_TESTS_STRING_H
#define MAIN_C_TESTS_STRING_H

#include "tasks/removeNonLetters.h"
#include "tasks/removeAdjacentEqualLetters.h"
#include "tasks/digitToStartLetterToEnd.h"
#include "tasks/reverseWords.h"
#include "tasks/turnDigitIntoSpaces.h"
#include "tasks/replaceWords.h"

#define ASSERT_STRING(got, expected) assertString ( expected , got , \
__FILE__ , __FUNCTION__ , __LINE__ )

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

//_____________________tests_tasks_________________________________//

void test_removeNonLetters_noSpace();

void test_removeNonLetters_withSpace();

void tests_removeNonLetters();
//_____________________________//

void test_removeAdjacentEqualLetters_stringWithSequences();

void test_removeAdjacentEqualLetters_emptyString();

void test_removeAdjacentEqualLetters_oneSymbol();

void test_removeAdjacentEqualLetters_stringWithoutSequences();

void tests_removeAdjacentEqualLetters();

//_____________________________//
void test_digitsToStartLettersToEnd_wordsWithDigits();

void test_digitsToStartLettersToEnd_emptyString();

void test_digitsToStartLettersToEnd_justLettersInWords();

void tests_digitsToStartLettersToEnd();

//_____________________________//

void test_reverseWords_notEmptyString();

void test_reverseWords_emptyString();

void tests_reverseWords();

//_____________________________//

void test_turnDigitIntoSpaces_stringWithDigits();

void test_turnDigitIntoSpaces_emptyString();

void test_turnDigitIntoSpaces_stringContainOnlyDigits();

void tests_turnDigitIntoSpaces();
//_____________________________//
//_____________________________//
//_____________________________//
//_____________________________//
void tests_tasks();

#endif //MAIN_C_TESTS_STRING_H
