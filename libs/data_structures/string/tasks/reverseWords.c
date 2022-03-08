//
// Created by lizka on 07.03.2022.
//

#include "reverseWords.h"

void reverseWords(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        reverseWord(word);
        beginSearch = word.end;
    }
}
