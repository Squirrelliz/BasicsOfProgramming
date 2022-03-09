//
// Created by lizka on 02.03.2022.
//

#ifndef MAIN_C_TESTS_STRING_H
#define MAIN_C_TESTS_STRING_H

#include <assert.h>
#include "tasks/removeNonLetters.h"
#include "tasks/removeAdjacentEqualLetters.h"
#include "tasks/digitToStartLetterToEnd.h"
#include "tasks/reverseWords.h"
#include "tasks/turnDigitIntoSpaces.h"
#include "tasks/replaceWords.h"
#include "tasks/isAlphabeticalOrder.h"
#include "tasks/printWordsOnePerLineInReversedOrder.h"
#include "tasks/countWordsPalindromes.h"
#include "tasks/getStringFromTheOtherTwo.h"
#include "tasks/reverseString.h"
#include "tasks/printWordBeforeFirstWordWithA.h"
#include "tasks/areIdenticalWordsInString.h"
#include "tasks/areWordsConsistFromTheSameLetters.h"
#include "tasks/getStringWithoutLastWord.h"
#include "tasks/lastMatch.h"

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

void test_replaceWords_replacementIsSmallerOriginal();

void test_replaceWords_replacementIsLargerOriginal();

void tests_replaceWordsSpaces();

//_____________________________//

void test_isAlphabeticalOrder_ordered();

void test_isAlphabeticalOrder_notOrdered();

void tests_isAlphabeticalOrder();

//_____________________________//

void test_printWordsOnePerLineInReversedOrder_notEmptyString();

void test_printWordsOnePerLineInReversedOrder_emptyString();

void tests_printWordsOnePerLineInReversedOrder();

//_____________________________//

void test_countWordsPalindromes_severalPalindromes();

void test_countWordsPalindromes_noPalindromes();

void tests_countWordsPalindromes();

//_____________________________//

void test_getStringFromTheOtherTwo_differentSizesOfStrings();

void test_getStringFromTheOtherTwo_identicalSizesOfStrings();

void test_getStringFromTheOtherTwo_emptyStrings();

void tests_getStringFromTheOtherTwo();

//_____________________________//

void test_reverseString_notEmptyString();

void test_reverseString_emptyString();

void tests_reverseString();

//_____________________________//
void testAll_getWordBeforeFirstWordWithA();
//_____________________________//

void test_areIdenticalWordsInString_severalIdenticalWords();

void test_areIdenticalWordsInString_noIdenticalWords();

void tests_areIdenticalWordsInString();

//_____________________________//

void test_areWordsConsistFromTheSameLetters_severalConsistFromTheSameLetters();

void test_areWordsConsistFromTheSameLetters_noConsistFromTheSameLetters();

void tests_areWordsConsistFromTheSameLetters();

//_____________________________//

void test_getStringWithoutLastWord_severalWordsLikeLast();

void test_getStringWithoutLastWord_noWordsLikeLast();

void tests_getStringWithoutLastWord();

//_____________________________//

void test_lastMatch_severalMatches();

void test_lastMatch_noMatch();

void tests_lastMatch();
//_____________________________//

void tests_tasks();

#endif //MAIN_C_TESTS_STRING_H
