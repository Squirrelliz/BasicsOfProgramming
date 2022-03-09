//
// Created by lizka on 09.03.2022.
//

#include "lastMatch.h"

WordDescriptor lastMatch(char *s1, char *s2) {

    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    WordDescriptor lastMatchWord;
    WordDescriptor *bagEnd = _bag.words + _bag.size;
    WordDescriptor *bagEnd2 = _bag2.words + _bag2.size;
    for (WordDescriptor *currentWord1 = _bag.words; currentWord1 < bagEnd; ++currentWord1) {
        for (WordDescriptor *currentWord2 = _bag2.words; currentWord2 < bagEnd2; ++currentWord2) {
            if (isIdenticalWords(*currentWord1, *currentWord2)) {
                lastMatchWord = *currentWord1;
                break;
            }
        }
    }

    return lastMatchWord;
}