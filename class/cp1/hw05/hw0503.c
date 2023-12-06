#include <stdio.h>
#include <stdint.h>
#include "mysphere.h"

int main() {
    double r = 0, a = 0, b = 0, c = 0, d = 0, area = 0;

    scanf("%lf%lf%lf%lf%lf", &r, &a, &b, &c, &d);

    int ret = get_cap_area(r, a, b, c, d, &area);

    printf("Return=%d, area=%lf\n", ret, area);

    return 0;
}
