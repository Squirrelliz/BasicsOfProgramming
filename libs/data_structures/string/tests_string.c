//
// Created by lizka on 02.03.2022.
//

#include "tests_string.h"
#define ASSERT_STRING(got,expected) assertString ( expected , got , \
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
    char s1[10]="hello";
    removeNonLetters(s1);
    char s2[10]="hello";
    ASSERT_STRING(s1,s2);
}

void test_removeNonLetters_withSpace() {
    char s1[]="hello, it's me";
    removeNonLetters(s1);
    char s2[]="hello,it'sme";
    ASSERT_STRING(s1,s2);
}

void tests_removeNonLetters() {
    test_removeNonLetters_noSpace();
    test_removeNonLetters_withSpace();
}
//_____________________________//

void test_removeAdjacentEqualLetters_stringWithSequences(){
    char s1[]="I wass woooondering    if after all these yearssss";
    removeAdjacentEqualLetters(s1);
    char s2[]="I was wondering if after al these years";
    ASSERT_STRING(s1,s2);
}

void test_removeAdjacentEqualLetters_emptyString(){
    char s1[]="";
    removeAdjacentEqualLetters(s1);
    char s2[]="";
    ASSERT_STRING(s1,s2);
}

void test_removeAdjacentEqualLetters_oneSymbol(){
    char s1[]=",";
    removeAdjacentEqualLetters(s1);
    char s2[]=",";
    ASSERT_STRING(s1,s2);
}

void test_removeAdjacentEqualLetters_stringWithoutSequences(){
    char s1[]="You'd like to me'et";
    removeAdjacentEqualLetters(s1);
    char s2[]="You'd like to me'et";
    ASSERT_STRING(s1,s2);
}

void tests_removeAdjacentEqualLetters(){
    test_removeAdjacentEqualLetters_stringWithSequences();
    test_removeAdjacentEqualLetters_oneSymbol();
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_stringWithoutSequences();
}
//_____________________________//
void test_digitsToStartLettersToEnd_wordsWithDigits(){
    char s1[]="T0o g0o o2ver1 eve5rything33";
    digitsToStartLettersToEnd(s1);
    char s2[]="0To 0go 12over 335everything";
    ASSERT_STRING(s1,s2);
}

void test_digitsToStartLettersToEnd_emptyString(){
    char s1[]="";
    digitsToStartLettersToEnd(s1);
    char s2[]="";
    ASSERT_STRING(s1,s2);
}


void test_digitsToStartLettersToEnd_justLettersInWords(){
    char s1[]="But I aint done much healing";
    digitsToStartLettersToEnd(s1);
    char s2[]="But I aint done much healing";
    ASSERT_STRING(s1,s2);
}

void tests_digitsToStartLettersToEnd(){
    test_digitsToStartLettersToEnd_wordsWithDigits();
    test_digitsToStartLettersToEnd_emptyString();
    test_digitsToStartLettersToEnd_justLettersInWords();
}
//_____________________________//

//_____________________________//
void tests_tasks() {
    tests_removeNonLetters();
    tests_removeAdjacentEqualLetters();
    tests_digitsToStartLettersToEnd();
}

