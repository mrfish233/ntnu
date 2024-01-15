#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    int32_t h=0,v=0;
    double rad = 0;

    if (scanf("%d %d", &h, &v) == 2) {
        rad = v * PI / 180.0;
        printf("%.0lf\n", ceil(h / sin(rad)));
    }

    return 0;
}
