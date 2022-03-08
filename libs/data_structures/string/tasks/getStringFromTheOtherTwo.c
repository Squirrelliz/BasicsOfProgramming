//
// Created by lizka on 08.03.2022.
//

#include "getStringFromTheOtherTwo.h"

void getStringFromTheOtherTwo(char *sRes, char *s1, char *s2) {
    if (*s1 == '\0' && *s2 == '\0') {
        *sRes = '\0';
        return;
    }
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            sRes = copy(word1.begin, word1.end, sRes);
            *sRes = ' ';
            sRes++;
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            sRes = copy(word2.begin, word2.end, sRes);
            *sRes = ' ';
            sRes++;
            beginSearch2 = word2.end;
        }
    }
    sRes--;
    *sRes = '\0';
}
