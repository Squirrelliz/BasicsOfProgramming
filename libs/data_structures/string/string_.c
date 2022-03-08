//
// Created by lizka on 01.03.2022.
//

#include "string_.h"


size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs++ == *rhs++) {}
    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t num = endSource - beginSource;

    memcpy(beginDestination, beginSource, num);

    return beginDestination + num;
}

char *copyIf_(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {

        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource))
            *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }

    return beginDestination;
}

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource > rendSource) {
        *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }

    return beginDestination;
}

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}


void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf_(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void reverseWord(WordDescriptor word) {
    char *endStringBuffer = copyReverse(word.end-1, word.begin-1,
                                        _stringBuffer);
    copy(_stringBuffer,endStringBuffer, word.begin);
}



