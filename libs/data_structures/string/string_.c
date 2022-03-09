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

char *findIf(char *begin, char *end, int (*f)(int)) {
    while (begin != end && !f(*begin))
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

int rGetWord(char *rBeginSearch, char *rEndSearch, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rBeginSearch, rEndSearch);

    if (word->end == rEndSearch)
        return 0;

    word->begin = findSpaceReverse(word->end, rEndSearch) + 1;
    word->end = word->end + 1;

    return 1;

}

int getCommaSeparatedWord(char *beginSearch, WordDescriptor *word) {
    char *endString = getEndOfString(beginSearch);
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return 0;

    word->end = find(word->begin, endString, ',');

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
    char *endStringBuffer = copyReverse(word.end - 1, word.begin - 1,
                                        _stringBuffer);
    copy(_stringBuffer, endStringBuffer, word.begin);
}

bool isIdenticalWords(WordDescriptor w1, WordDescriptor w2) {
    if (w1.end - w1.begin != w2.end - w2.begin)
        return 0;
    while (w1.begin != w1.end) {
        if (*w1.begin != *w2.begin)
            return 0;
        w1.begin++;
        w2.begin++;
    }
    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != w1.end && w2.begin != w2.end && *w1.begin == *w2.begin) {
        w1.begin++;
        w2.begin++;
    }

    return *w1.begin - *w2.begin;
}

int getIdenticalWord(char *beginSearch, WordDescriptor *word, WordDescriptor wordToFind) {
    while (getWord(beginSearch, word)) {
        if (isIdenticalWords(*word, wordToFind)) {
            return 1;
        } else {
            beginSearch = word->end;
        }
    }
    return 0;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;

    WordDescriptor word;
    while (getWord(s, &word)) {
        bag->words[bag->size++] = word;
        s = word.end;
    }
}

void printWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);

    *endStringBuffer = '\0';

    printf("%s", _stringBuffer);
}

bool isPalindrome(WordDescriptor word) {
    char *left = word.begin;
    char *right = word.end - 1;

    while (left < right) {
        if (*left != *right)
            return false;

        left++;
        right--;
    }

    return true;
}

bool doesWordContainA(WordDescriptor word) {
    char *read = word.begin;
    while (read != word.end) {
        if (*read == 'a' || *read == 'A')
            return true;

        read++;
    }
    return false;
}


