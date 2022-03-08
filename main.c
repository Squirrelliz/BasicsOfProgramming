#include <stdio.h>
#include "libs/data_structures/string/tests_string.h"
#include <malloc.h>

int main() {
    tests_tasks();
    //char w1[] = "a";
    //char w2[] = "";
    //size_t w1Size = strlen_(w1);
    //size_t w2Size = strlen_(w2);
    //WordDescriptor word1 = {w1, w1 + w1Size};
    //WordDescriptor word2 = {w2, w2 + w2Size};
    //printf("%d", areWordsEqual(word1,word2));
   // char *beginString = malloc(sizeof(char) * 6);
   // gets(beginString);
   // puts(beginString);
   // WordDescriptor lastWord;
   // if (!getWord(beginString, &lastWord)) {
   //     printf("true");
   //     return 0;
   // }
   // beginString = lastWord.end;
   // WordDescriptor currentWord;
   // while (getWord(beginString, &currentWord)) {
   //     if (areWordsEqual(lastWord, currentWord) > 0) {
   //         printf("false");
   //         return 0;
   //     }
   //     lastWord = currentWord;
   //     beginString = lastWord.end;
   // }

    return 0;
}
