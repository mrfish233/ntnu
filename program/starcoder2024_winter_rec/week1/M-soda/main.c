#include <stdio.h>
#include <stdint.h>

int32_t totalSoda(int32_t num, int32_t mod) {
    int32_t total = 0;

    while (num >= mod) {
        total += num / mod;
        num = num / mod + num % mod;
    }

    return total;
}

int main() {
    int32_t cases = 0;
    scanf("%d", &cases);

    while (cases--) {
        int32_t num1 = 0, num2 = 0, mod = 0;
        scanf("%d%d%d", &num1, &num2, &mod);

        printf("%d\n", totalSoda(num1 + num2, mod));
    }

    return 0;
}
