#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t velocity = 0, time = 0;

    while (scanf("%d%d", &velocity, &time) != EOF) {
        printf("%d\n", 2 * velocity * time);
    }

    return 0;
}
