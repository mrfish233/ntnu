#include <stdio.h>
#include <stdint.h>

void parity(int32_t num) {
    int32_t offset = 0, temp = num;
    while (temp > 0) {
        temp = temp >> 1;
        offset++;
    }

    printf("The parity of ");

    int32_t parityOne = 0;
    while (offset > 0) {
        offset--;

        int32_t bit = (num >> offset) % 2;
        printf("%d", bit);

        if (bit == 1) {
            parityOne++;
        }
    }

    printf(" is %d (mod 2).\n", parityOne);

    return;
}

int main() {
    while (1) {
        int32_t num = 0;
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        parity(num);
    }

    return 0;
}
