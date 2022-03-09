//
// Created by lizka on 07.03.2022.
//

#include "digitToStartLetterToEnd.h"

void digitsToStartLettersToEnd(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }

}
