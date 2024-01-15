#include <stdio.h>
#include <stdint.h>

int32_t totalBetterSales(int32_t sales[], int32_t days) {
    int32_t total = 0;

    int32_t i = 0, j = 0;
    for (i = 1; i < days; i++) {
        for (j = 0; j < i; j++) {
            total += (sales[j] <= sales[i]);
        }
    }

    return total;
}

int main() {
    int32_t cases = 0;
    scanf("%d", &cases);

    while (cases--) {
        int32_t days = 0;
        scanf("%d", &days);

        int32_t i = 0, sales[1000] = {0};
        for (i = 0; i < days; i++) {
            scanf("%d", &sales[i]);
        }

        printf("%d\n", totalBetterSales(sales, days));
    }

    return 0;
}
