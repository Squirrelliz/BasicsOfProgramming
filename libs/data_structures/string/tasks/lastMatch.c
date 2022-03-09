//
// Created by lizka on 09.03.2022.
//

#include "lastMatch.h"

WordDescriptor lastMatch(char *s1, char *s2) {

    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    WordDescriptor lastMatchWord;
    for (int i = 0; i < _bag.size; ++i) {
        for (int j = 0; j < _bag2.size; ++j) {
            if (isIdenticalWords(_bag.words[i], _bag2.words[j])) {
                lastMatchWord = _bag.words[i];
                break;
            }
        }
    }

    return lastMatchWord;
}