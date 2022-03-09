//
// Created by lizka on 09.03.2022.
//

#include "printWordBeforeFirstWordWithA.h"

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *wordFound) {
    WordDescriptor lastWord;
    if (!getWord(s, &lastWord))
        return EMPTY_STRING;

    if (doesWordContainA(lastWord))
        return FIRST_WORD_WITH_A;


    s = lastWord.end;
    WordDescriptor currentWord;
    while (getWord(s, &currentWord)) {
        if (doesWordContainA(currentWord)) {
            *wordFound = lastWord;
            return WORD_FOUND;
        }

        lastWord = currentWord;
        s = lastWord.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor wordFound;
    if (getWordBeforeFirstWordWithA(s, &wordFound) == WORD_FOUND)
        printWord(wordFound);
}
