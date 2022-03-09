//
// Created by lizka on 09.03.2022.
//

#include "getStringWithoutLastWord.h"

void getStringWithoutLastWord(char *sRes, char *sOriginal) {
    WordDescriptor lastWord;
    rGetWord(getEndOfString(sOriginal) - 1, sOriginal - 1, &lastWord);

    WordDescriptor currentWord;
    while (getWord(sOriginal, &currentWord)) {
        if (!isIdenticalWords(lastWord, currentWord)) {
            sRes = copy(currentWord.begin, currentWord.end, sRes);
            *sRes = ' ';
            sRes++;
        }
        sOriginal = currentWord.end;
    }

    sRes--;
    *sRes = '\0';
}
