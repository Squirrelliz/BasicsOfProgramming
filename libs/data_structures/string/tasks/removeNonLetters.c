//
// Created by lizka on 02.03.2022.
//

#include "removeNonLetters.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf_(s, endSource, s, isgraph);
    *destination = '\0' ;
}
