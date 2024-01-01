#include <stdio.h>
#include <stdint.h>

int32_t sumOfDigits(int32_t num) {
    int32_t total = 0;

    while (num > 0) {
        total += num % 10;
        num /= 10;
    }

    if (total >= 10) {
        return sumOfDigits(total);
    }

    return total;
}

int main() {
    int32_t num = -1;

    while(1) {
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        printf("%d\n", sumOfDigits(num));
    }

    return 0;
}
