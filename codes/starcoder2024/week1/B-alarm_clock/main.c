#include <stdio.h>
#include <stdint.h>

int32_t totalMin(int32_t startHour, int32_t startMin, int32_t endHour, int32_t endMin) {
    int32_t result = 0, offset = 0;

    if (startHour > endHour || (startHour == endHour && startMin > endMin)) {
        offset = 24 * 60;
    }

    int32_t start = startHour * 60 + startMin;
    int32_t end   = endHour   * 60 + endMin;

    result = end - start + offset;

    return result;
}

int main() {
    int32_t startHour = -1, startMin = -1, endHour = -1, endMin = -1;

    while (1) {
        scanf("%d%d%d%d", &startHour, &startMin, &endHour, &endMin);

        if (startHour == 0 && startMin == 0 && endHour == 0 && endMin == 0) {
            break;
        }

        printf("%d\n", totalMin(startHour, startMin, endHour, endMin));
    }

    return 0;
}
