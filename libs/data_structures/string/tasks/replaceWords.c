//
// Created by lizka on 08.03.2022.
//

#include "replaceWords.h"

void replaceWords(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    WordDescriptor foundWord;
    while (getIdenticalWord(readPtr, &foundWord, word1)) {
        recPtr = copy(readPtr, foundWord.begin, recPtr);
        recPtr = copy(word2.begin, word2.end, recPtr);
        readPtr = foundWord.end;
    }

    char *endSource = getEndOfString(readPtr);
    recPtr = copy(readPtr, endSource, recPtr);
    *recPtr = '\0';
}
