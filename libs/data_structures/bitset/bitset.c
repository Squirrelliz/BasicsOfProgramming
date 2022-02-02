//
// Created by lizka on 02.02.2022.
//

#include <stdio.h>
#include <assert.h>
#include "bitset.h"

// возвращает пустое множество c универсумом 0, 1,..., maxValue
bitset bitset_create(uint32_t maxValue) {
    assert(maxValue >= 0 && maxValue < 32);
    return (bitset) {0, maxValue};
}
// возвращает значение ’истина’, если значение value больше нуля и меньше максимального элемента универсума
// множества set, иначе - ’ложь’
bool bitset_checkValue(bitset set, uint32_t value) {
    return value >= 0 && value <= set.maxValue;
}

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in(bitset set, uint32_t value) {
    assert(bitset_checkValue(set, value));
    return set.values & 1 << value;
}

// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitset_isSubset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}

// добавляет элемент value в множество set
void bitset_insert(bitset *set, uint32_t value) {
    assert(value <= set->maxValue);
    set->values |= 1 << value;
}

// удаляет элемент value из множества set
void bitset_deleteElement(bitset *set, uint32_t value) {
    assert(value <= set->maxValue);
    set->values &= ~(1 << value);
}


// возвращает объединение множеств set1 и set2
bitset bitset_union(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

// возвращает пересечение множеств set1 и set2
bitset bitset_intersection(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

// возвращает разность множеств set1 и set2
bitset bitset_difference(bitset set1, bitset set2) {
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

// возвращает дополнение до универсума множества set
bitset bitset_complement(bitset set) {
    uint32_t n = 32 - set.maxValue;
    return (bitset) {(~set.values << n) >> n, set.maxValue};
}

// вывод множества set
void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

