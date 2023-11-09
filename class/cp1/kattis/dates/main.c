#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t a=0, b=0, c=0;

    if (scanf("%d/%d/%d", &a, &b, &c) == 3) {
        if (a <= 12 && b <= 12) printf("either\n");
        else if (a > 12) printf("EU\n");
        else printf("US\n");
    }

    return 0;
}
