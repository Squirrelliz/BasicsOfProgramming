//
// Created by lizka on 09.03.2022.
//

#ifndef MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, WordDescriptor *wordFound);

void printWordBeforeFirstWordWithA(char *s);

#endif //MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H
