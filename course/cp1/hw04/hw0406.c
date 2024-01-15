#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 10000000000

// int32_t array[SIZE] = {0};

int main() {
    // int32_t array[SIZE] = {0};
    // static int32_t array[SIZE] = {0};
    int32_t *array = calloc(SIZE, sizeof(int32_t));

    if (array == NULL) {
        printf("Array is too big.\n");
        return 1;
    }

    for (int32_t i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    // array[SIZE-1] = SIZE-1;

    printf("first: %ld, last: %ld\n", array[0], array[SIZE-1]);

    free(array);

    return 0;
}
