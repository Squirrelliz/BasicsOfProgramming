//
// Created by lizka on 09.03.2022.
//

#include "areIdenticalWordsInString.h"

bool areIdenticalWordsInString(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; ++i) {
        for (int j = i + 1; j < _bag.size; ++j) {
            if (isIdenticalWords(_bag.words[i], _bag.words[j]))
                return true;
        }
    }

    return false;
}
