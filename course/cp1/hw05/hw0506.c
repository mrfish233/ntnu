#include <stdio.h>
#include <stdint.h>

int main()
{
    int16_t array[10] = {0};

    // Alice

    for (int32_t i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

    for (int32_t i = 5; i > 0; i--) {
        printf("%d ", array[i-1]);
    }

    // Bob

    // for (int32_t i = 5; i > 0; i--)
    // {
    //     scanf("%d", &array[i - 1]);
    // }

    // for (int32_t i = 0; i < 5; i++)
    // {
    //     printf("%d ", array[i]);
    // }

    printf("\n");
    return 0;
}
