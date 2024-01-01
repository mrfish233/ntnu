#include <stdio.h>
#include <stdint.h>

int32_t numberOfPastes(int32_t num) {
    int32_t result = 0;
    num--;

    while (num > 0) {
        num = num >> 1;
        result++;
    }

    return result;
}

int main() {
    int32_t i = 0;
    while (1) {
        int32_t num = 0;
        scanf("%d", &num);

        if (num < 0) {
            break;
        }

        printf("Case %d: %d\n", ++i, numberOfPastes(num));
    }

    return 0;
}
