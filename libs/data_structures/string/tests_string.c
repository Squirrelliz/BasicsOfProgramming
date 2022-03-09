//
// Created by lizka on 02.03.2022.
//

#include "tests_string.h"

#define ASSERT_STRING(got, expected) assertString ( expected , got , \
__FILE__ , __FUNCTION__ , __LINE__ )

void assertString(const char *expected, char *got, const char *fileName, const char *funcName, int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

//_____________________tests_tasks_________________________________//

//_____________________________//
void test_removeNonLetters_noSpace() {
    char s1[10] = "hello";
    removeNonLetters(s1);
    char s2[10] = "hello";
    ASSERT_STRING(s1, s2);
}

void test_removeNonLetters_withSpace() {
    char s1[] = "hello, it's me";
    removeNonLetters(s1);
    char s2[] = "hello,it'sme";
    ASSERT_STRING(s1, s2);
}

void tests_removeNonLetters() {
    test_removeNonLetters_noSpace();
    test_removeNonLetters_withSpace();
}
//_____________________________//

void test_removeAdjacentEqualLetters_stringWithSequences() {
    char s1[] = "I wass woooondering    if after all these yearssss";
    removeAdjacentEqualLetters(s1);
    char s2[] = "I was wondering if after al these years";
    ASSERT_STRING(s1, s2);
}

void test_removeAdjacentEqualLetters_emptyString() {
    char s1[] = "";
    removeAdjacentEqualLetters(s1);
    char s2[] = "";
    ASSERT_STRING(s1, s2);
}

void test_removeAdjacentEqualLetters_oneSymbol() {
    char s1[] = ",";
    removeAdjacentEqualLetters(s1);
    char s2[] = ",";
    ASSERT_STRING(s1, s2);
}

void test_removeAdjacentEqualLetters_stringWithoutSequences() {
    char s1[] = "You'd like to me'et";
    removeAdjacentEqualLetters(s1);
    char s2[] = "You'd like to me'et";
    ASSERT_STRING(s1, s2);
}

void tests_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_stringWithSequences();
    test_removeAdjacentEqualLetters_oneSymbol();
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_stringWithoutSequences();
}

//_____________________________//
void test_digitsToStartLettersToEnd_wordsWithDigits() {
    char s1[] = "T0o g0o o2ver1 eve5rything33";
    digitsToStartLettersToEnd(s1);
    char s2[] = "0To 0go 12over 335everything";
    ASSERT_STRING(s1, s2);
}

void test_digitsToStartLettersToEnd_emptyString() {
    char s1[] = "";
    digitsToStartLettersToEnd(s1);
    char s2[] = "";
    ASSERT_STRING(s1, s2);
}


void test_digitsToStartLettersToEnd_justLettersInWords() {
    char s1[] = "But I aint done much healing";
    digitsToStartLettersToEnd(s1);
    char s2[] = "But I aint done much healing";
    ASSERT_STRING(s1, s2);
}

void tests_digitsToStartLettersToEnd() {
    test_digitsToStartLettersToEnd_wordsWithDigits();
    test_digitsToStartLettersToEnd_emptyString();
    test_digitsToStartLettersToEnd_justLettersInWords();
}

//_____________________________//
void test_reverseWords_notEmptyString() {
    char s1[] = ",olleH nac uoy raeh ?em";
    reverseWords(s1);
    char s2[] = "Hello, can you hear me?";
    ASSERT_STRING(s1, s2);
}

void test_reverseWords_emptyString() {
    char s1[] = "";
    reverseWords(s1);
    char s2[] = "";
    ASSERT_STRING(s1, s2);
}

void tests_reverseWords() {
    test_reverseWords_notEmptyString();
    test_reverseWords_emptyString();
}

//_____________________________//
void test_turnDigitIntoSpaces_stringWithDigits() {
    char s1[] = "I'm2in3Californi00a1";
    turnDigitIntoSpaces(s1);
    char s2[] = "I'm  in   California ";
    ASSERT_STRING(s1, s2);
}

void test_turnDigitIntoSpaces_emptyString() {
    char s1[] = "";
    turnDigitIntoSpaces(s1);
    char s2[] = "";
    ASSERT_STRING(s1, s2);
}

void test_turnDigitIntoSpaces_stringContainOnlyDigits() {
    char s1[] = "3";
    turnDigitIntoSpaces(s1);
    char s2[] = "   ";
    ASSERT_STRING(s1, s2);
}

void tests_turnDigitIntoSpaces() {
    test_turnDigitIntoSpaces_stringWithDigits();
    test_turnDigitIntoSpaces_emptyString();
    test_turnDigitIntoSpaces_stringContainOnlyDigits();
}

//_____________________________//
void test_replaceWords_replacementIsSmallerOriginal() {
    char s1[] = "This is the enderman . For this is the enderman .";
    char w1[] = "enderman";
    char w2[] = "end";
    replaceWords(s1, w1, w2);
    char s2[] = "This is the end . For this is the end .";
    ASSERT_STRING(s1, s2);
}

void test_replaceWords_replacementIsLargerOriginal() {
    char s1[] = "At Sky , at Sky . Sky is where we start...";
    char w1[] = "Sky";
    char w2[] = "Skyfall";
    replaceWords(s1, w1, w2);
    char s2[] = "At Skyfall , at Skyfall . Skyfall is where we start...";
    ASSERT_STRING(s1, s2);
}


void tests_replaceWordsSpaces() {
    test_replaceWords_replacementIsSmallerOriginal();
    test_replaceWords_replacementIsLargerOriginal();
}

//_____________________________//
void test_isAlphabeticalOrder_ordered() {
    char s[] = "abs dasr dfwd zz";

    assert(isAlphabeticalOrder(s) == true);

    printf("test_isAlphabeticalOrder_ordered - OK\n");
}

void test_isAlphabeticalOrder_notOrdered() {
    char s[] = "bnkdk akfv";

    assert(isAlphabeticalOrder(s) == false);

    printf("test_isAlphabeticalOrder_notOrdered - OK\n");
}

void tests_isAlphabeticalOrder() {
    test_isAlphabeticalOrder_ordered();
    test_isAlphabeticalOrder_notOrdered();
}

//_____________________________//
void test_printWordsOnePerLineInReversedOrder_notEmptyString() {
    char s[] = "OK - test_printWordsOnePerLineInReversedOrder_notEmptyString";
    printWordsOnePerLineInReversedOrder(s);
}

void test_printWordsOnePerLineInReversedOrder_emptyString() {
    char s[] = "";
    printWordsOnePerLineInReversedOrder(s);
}

void tests_printWordsOnePerLineInReversedOrder() {
    test_printWordsOnePerLineInReversedOrder_notEmptyString();
    test_printWordsOnePerLineInReversedOrder_emptyString();
}

//_____________________________//
void test_countWordsPalindromes_severalPalindromes() {
    char s[] = "abs,dfd,uuuu,hgf";

    assert(countWordsPalindromes(s) == 2);

    printf("test_countWordsPalindromes_severalPalindromes - OK\n");
}

void test_countWordsPalindromes_noPalindromes() {
    char s[] = "bnkdk akfv";

    assert(countWordsPalindromes(s) == 0);

    printf("test_countWordsPalindromes_noPalindromes - OK\n");
}

void tests_countWordsPalindromes() {
    test_countWordsPalindromes_severalPalindromes();
    test_countWordsPalindromes_noPalindromes();
}

//_____________________________//
void test_getStringFromTheOtherTwo_differentSizesOfStrings() {
    char s1[] = "When collide, days dark...";
    char s2[] = "worlds and are";
    char sGotRes[MAX_STRING_SIZE];
    getStringFromTheOtherTwo(sGotRes, s1, s2);
    char sExpectedRes[] = "When worlds collide, and days are dark...";
    ASSERT_STRING(sGotRes, sExpectedRes);
}

void test_getStringFromTheOtherTwo_identicalSizesOfStrings() {
    char s1[] = "Let sky";
    char s2[] = "the fall.";
    char sGotRes[MAX_STRING_SIZE];
    getStringFromTheOtherTwo(sGotRes, s1, s2);
    char sExpectedRes[] = "Let the sky fall.";
    ASSERT_STRING(sGotRes, sExpectedRes);
}

void test_getStringFromTheOtherTwo_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    char sGotRes[MAX_STRING_SIZE];
    getStringFromTheOtherTwo(sGotRes, s1, s2);
    char sExpectedRes[] = "";
    ASSERT_STRING(sGotRes, sExpectedRes);
}

void tests_getStringFromTheOtherTwo() {
    test_getStringFromTheOtherTwo_differentSizesOfStrings();
    test_getStringFromTheOtherTwo_identicalSizesOfStrings();
    test_getStringFromTheOtherTwo_emptyStrings();
}

//_____________________________//
void test_reverseString_notEmptyString() {
    char s1[] = "crumbles it When";
    reverseString(s1);
    char s2[] = "When it crumbles";
    ASSERT_STRING(s1, s2);
}

void test_reverseString_emptyString() {
    char s1[] = "";
    reverseString(s1);
    char s2[] = "";
    ASSERT_STRING(s1, s2);
}


void tests_reverseString() {
    test_reverseString_notEmptyString();
    test_reverseString_emptyString();
}

//_____________________________//
void testAll_getWordBeforeFirstWordWithA() {
    WordDescriptor word;

    char s1[] = "";
    assert (
            getWordBeforeFirstWordWithA(s1, &word)
            == EMPTY_STRING
    );

    char s2[] = " ABC";
    assert (
            getWordBeforeFirstWordWithA(s2, &word)
            == FIRST_WORD_WITH_A
    );

    char s3[] = "BC A";
    assert (
            getWordBeforeFirstWordWithA(s3, &word)
            == WORD_FOUND
    );
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING ("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s4, &word) ==
            NOT_FOUND_A_WORD_WITH_A);
}

//_____________________________//
void test_areIdenticalWordsInString_severalIdenticalWords() {
    char s[] = "abs dfd abs hgf hgf ii";

    assert(areIdenticalWordsInString(s) == true);

    printf("test_areIdenticalWordsInString_severalIdenticalWords - OK\n");
}

void test_areIdenticalWordsInString_noIdenticalWords() {
    char s[] = "bnkdk akfv frfh sis";

    assert(areIdenticalWordsInString(s) == false);

    printf("test_areIdenticalWordsInString_noIdenticalWords - OK\n");
}

void tests_areIdenticalWordsInString() {
    test_areIdenticalWordsInString_severalIdenticalWords();
    test_areIdenticalWordsInString_noIdenticalWords();
}

//_____________________________//

void test_areWordsConsistFromTheSameLetters_severalConsistFromTheSameLetters() {
    char s[] = "bas dfd bsa hgf ghf ii";

    assert(areWordsConsistFromTheSameLetters(s) == true);

    printf("test_areWordsConsistFromTheSameLetters_severalConsistFromTheSameLetters - OK\n");
}

void test_areWordsConsistFromTheSameLetters_noConsistFromTheSameLetters() {
    char s[] = "bnkdk akfv frfh sis";

    assert(areWordsConsistFromTheSameLetters(s) == false);

    printf("test_areWordsConsistFromTheSameLetters_noConsistFromTheSameLetters - OK\n");
}

void tests_areWordsConsistFromTheSameLetters() {
    test_areWordsConsistFromTheSameLetters_severalConsistFromTheSameLetters();
    test_areWordsConsistFromTheSameLetters_noConsistFromTheSameLetters();
}

//_____________________________//
void tests_tasks() {
    tests_removeNonLetters();
    tests_removeAdjacentEqualLetters();
    tests_digitsToStartLettersToEnd();
    tests_reverseWords();
    tests_turnDigitIntoSpaces();
    tests_replaceWordsSpaces();
    tests_isAlphabeticalOrder();
    tests_printWordsOnePerLineInReversedOrder();
    tests_countWordsPalindromes();
    tests_getStringFromTheOtherTwo();
    tests_reverseString();
    testAll_getWordBeforeFirstWordWithA();
    tests_areIdenticalWordsInString();
    tests_areWordsConsistFromTheSameLetters();
}

