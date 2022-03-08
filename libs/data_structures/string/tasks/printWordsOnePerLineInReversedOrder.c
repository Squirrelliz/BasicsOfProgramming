//
// Created by lizka on 08.03.2022.
//

#include "printWordsOnePerLineInReversedOrder.h"

void printWordsOnePerLineInReversedOrder(char *beginString) {
    getBagOfWords(&_bag, beginString);

    for (int i = _bag.size - 1; i >= 0; i--) {
        printWord(_bag.words[i]);
        printf("\n");
    }
}
