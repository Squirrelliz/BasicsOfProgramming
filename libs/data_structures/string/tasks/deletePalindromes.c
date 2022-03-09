//
// Created by lizka on 09.03.2022.
//

#include "deletePalindromes.h"

void deletePalindromes(char *s) {
    WordDescriptor currentWord;

    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    *endBuffer = '\0';
    char *beginBuffer = _stringBuffer;
    while (getWord(beginBuffer, &currentWord)) {
        if (!isPalindrome(currentWord)) {
            s = copy(currentWord.begin, currentWord.end, s);
            *s = ' ';
            s++;
        }
        beginBuffer = currentWord.end;
    }

    s--;
    *s = '\0';
}
