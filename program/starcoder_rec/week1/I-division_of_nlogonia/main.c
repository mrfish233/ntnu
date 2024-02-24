#include <stdio.h>
#include <stdint.h>

void checkHomeCountry(int32_t divX, int32_t divY, int32_t x, int32_t y) {
    if (x == divX || y == divY) {
        printf("divisa\n");
    } else if (x > divX) {
        if (y > divY) {
            printf("NE\n");
        } else {
            printf("SE\n");
        }
    } else {
        if (y > divY) {
            printf("NO\n");
        } else {
            printf("SO\n");
        }
    }

    return;
}

int main() {
    while (1) {
        int32_t cases = 0;
        scanf("%d", &cases);

        if (cases == 0) {
            break;
        }

        int32_t divX = 0, divY = 0;
        scanf("%d%d", &divX, &divY);

        int32_t i = 0;
        for (i = 0; i < cases; i++) {
            int32_t x = 0, y = 0;
            scanf("%d%d", &x, &y);

            checkHomeCountry(divX, divY, x, y);
        }
    }

    return 0;
}
