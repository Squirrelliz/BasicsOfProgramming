//
// Created by lizka on 08.03.2022.
//

#include "turnDigitIntoSpaces.h"

void turnDigitIntoSpaces(char *beginString) {
    char *endString = getEndOfString(beginString);
    char *endStringBuffer = copy(beginString, endString, _stringBuffer);
    char *beginStringBuffer = _stringBuffer;
    endString = beginString;
    while (endString - beginString < MAX_STRING_SIZE && beginStringBuffer < endStringBuffer) {
        if (isdigit(*beginStringBuffer)) {
            int nSpaces = *beginStringBuffer - '0';
            for (int i = 0; endString - beginString < MAX_STRING_SIZE && i < nSpaces; ++i) {
                *endString = ' ';
                endString++;
            }
        } else {
            *endString = *beginStringBuffer;
            endString++;
        }

        beginStringBuffer++;
    }

    *endString = '\0';
}
