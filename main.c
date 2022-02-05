#include "libs/data_structures/vector/vectorVoid.h"

int main() {
    int data[3]={1,2,3};
    vectorVoid v = {data,3,3, sizeof(int )};
    return 0;
}
