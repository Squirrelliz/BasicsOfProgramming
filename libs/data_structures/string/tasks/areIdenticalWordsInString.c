//
// Created by lizka on 09.03.2022.
//

#include "areIdenticalWordsInString.h"

bool areIdenticalWordsInString(char *s) {
    getBagOfWords(&_bag, s);
    WordDescriptor *bagEnd = _bag.words + _bag.size;
    for (WordDescriptor *currentWord1 = _bag.words; currentWord1 < bagEnd; ++currentWord1) {
        for (WordDescriptor *currentWord2 = currentWord1 + 1; currentWord2 < bagEnd; ++currentWord2) {
            if (isIdenticalWords(*currentWord1, *currentWord2))
                return true;
        }
    }

    return false;
}
