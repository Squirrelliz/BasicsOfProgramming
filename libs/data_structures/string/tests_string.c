//
// Created by lizka on 02.03.2022.
//

#include "tests_string.h"

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

void test_removeNonLetters_noSpace() {
    char s1[10]="hello";
    removeNonLetters(s1);
    char s2[10]="hello";
    assertString(s1,s2,"removeNonLetters.h", "test_removeNonLetters_noSpace",27);
}

void test_removeNonLetters_withSpace() {
    char s1[]="hello, it's me";
    removeNonLetters(s1);
    char s2[]="hello,it'sme";
    assertString(s1,s2,"removeNonLetters.h", "test_removeNonLetters_noSpace",33);
}

void tests_removeNonLetters() {
    test_removeNonLetters_noSpace();
    test_removeNonLetters_withSpace();
}

void tests_tasks() {
    tests_removeNonLetters();
}
