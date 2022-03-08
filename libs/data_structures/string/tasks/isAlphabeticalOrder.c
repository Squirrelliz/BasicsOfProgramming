//
// Created by lizka on 08.03.2022.
//

#include "isAlphabeticalOrder.h"

bool isAlphabeticalOrder(char *beginString) {
    WordDescriptor lastWord;
    if (!getWord(beginString, &lastWord))
        return true;

    beginString = lastWord.end;
    WordDescriptor currentWord;
    while (getWord(beginString, &currentWord)) {
        if (areWordsEqual(lastWord, currentWord) > 0)
            return false;
        lastWord = currentWord;
        beginString = lastWord.end;
    }
    return true;
}
