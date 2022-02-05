#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/vector/vector_tests.h"

int main() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);

        printf("%d ", x);
    }

    vectorVoid v1 = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v1, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v1, i, &x);

        printf("%f ", x);
    }

    test();

    return 0;
}
