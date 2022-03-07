//
// Created by lizka on 02.03.2022.
//

#include "removeAdjacentEqualLetters.h"

void removeAdjacentEqualLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = s+1;
    if(s+1 == endSource || s==endSource)
        return;
    s++;
    while (s != endSource) {
        if (*(s + 1) != *s) {
            destination = copy(s, s + 1, destination);
        }
        s++;
    }
    *destination='\0';
}
