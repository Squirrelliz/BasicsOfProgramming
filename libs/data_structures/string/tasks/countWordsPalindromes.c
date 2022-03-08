//
// Created by lizka on 08.03.2022.
//

#include "countWordsPalindromes.h"

int countWordsPalindromes(char *beginString) {
    WordDescriptor word;
    int count = 0;
    while (getCommaSeparatedWord(beginString, &word)) {
        if (isPalindrome(word)) {
            count++;
        }
        if (*beginString != '\0')
            beginString = word.end + 1;
    }
    return count;
}
