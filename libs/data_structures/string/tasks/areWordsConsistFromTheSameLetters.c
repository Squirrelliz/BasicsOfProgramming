//
// Created by lizka on 09.03.2022.
//

#include "areWordsConsistFromTheSameLetters.h"

bool areWordsConsistFromTheSameLetters(char *s) {
    char *endStringBuffer = copy(s, getEndOfString(s), _stringBuffer);
    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; ++i) {
        sortLettersInWord(&_bag.words[i]);
    }

    return areIdenticalWordsInString(s);
}
