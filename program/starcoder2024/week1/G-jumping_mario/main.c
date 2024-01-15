#include <stdio.h>
#include <stdint.h>

void jumpCheck(int32_t height[], int32_t walls) {
    int32_t highJump = 0, lowJump = 0;

    int32_t i = 0;
    for (i = 1; i < walls; i++) {
        if (height[i-1] > height[i]) {
            lowJump++;
        } else if (height[i-1] < height[i]) {
            highJump++;
        }
    }

    printf("%d %d\n", highJump, lowJump);

    return;
}

int main() {
    int32_t cases = 0;

    scanf("%d", &cases);

    int32_t i = 0;
    for (i = 0; i < cases; i++) {
        int32_t height[50] = {0}, walls = 0;

        scanf("%d", &walls);

        int32_t j = 0;
        for (j = 0; j < walls; j++) {
            scanf("%d", &height[j]);
        }

        printf("Case %d: ", i + 1);
        jumpCheck(height, walls);
    }

    return 0;
}
