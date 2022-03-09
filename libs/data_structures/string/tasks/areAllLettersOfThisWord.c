//
// Created by lizka on 09.03.2022.
//

#include "areAllLettersOfThisWord.h"

bool areAllLettersOfThisWord(char *s, WordDescriptor word) {
    bool availability[CHAR_MAX + 1] = {false};
    char *end = getEndOfString(s);
    while (s != end) {
        availability[*s] = true;
        s++;
    }

    while (word.begin != word.end) {
        if (!availability[*word.begin])
            return false;
        word.begin++;
    }
    return true;
}
