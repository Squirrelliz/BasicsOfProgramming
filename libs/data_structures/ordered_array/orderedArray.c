//
// Created by lizka on 02.02.2022.
//

#include "orderedArray.h"
//освобождает неиспользуемую оперативную память, отведённую под множество a
static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a, size_t
size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);
    return set;
}

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t ordered_array_set_in(ordered_array_set set, int value) {
    return binarySearch(set.data,set.size,value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value){
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(*set, value) == set->size){
        append(set->data,&set->size, value);
        insertionSort(set->data,set->size);
    }
}


//void ordered_array_set_insert_(ordered_array_set *set, int value) {
//    ordered_array_set_isAbleAppend(set);
//    if (ordered_array_set_in(set, value) == set->size) {
//        int index = binarySearchCriteria(set->data,set->size,value,isMore);
//        assert(index<=set->size);
//        if (set->size != 0) {
//            size_t lowBound = (index == 0) ? set->capacity : index;
//            (set->size)++;
//            for (size_t i = set->data; i != lowBound; i --)
//                set->data[i] = set->data[i - 1];
//            set->data[index] = value;
//        } else {
//            (set->size)++;
//            set->data[index] = value;
//        }
//    }
//}
//
// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set, int value){
    size_t deleteElementIndex = ordered_array_set_in(*set, value);
    if (deleteElementIndex < set->size)
        deleteByPosSaveOrder(set->data, &set->size, deleteElementIndex);
}

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2){
    ordered_array_set setUnion = ordered_array_set_create(set1.size + set2.size);
    setUnion.size = set1.size;
    memcpy(setUnion.data, set1.data, set1.size * sizeof(int));
    for (int i = 0; i < set2.size; i++) {
        ordered_array_set_insert(&setUnion, set2.data[i]);
    }
    return setUnion;
}

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2){
    ordered_array_set setIntersection = ordered_array_set_create(set1.size);
    for (int i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(set2, set1.data[i]) != set2.size)
            ordered_array_set_insert(&setIntersection, set1.data[i]);
    }
    return setIntersection;
}

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2){

}

