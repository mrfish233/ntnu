#include "mysphere.h"

#define PI 3.141592653589793238

int32_t get_cap_area(double r, double a, double b, double c, double d, double *pArea) {
    if (r < 0 || pArea == NULL) {
        return -1;
    }

    // Square distance from origin is (a*0 + b*0 + c*0 - d)^2 / (a^2 + b^2 + c^2)
    double planeSquareDist = d * d / (a * a + b * b + c * c);

    if (planeSquareDist > r * r) {
        return 0;
    }

    *pArea = (r * r - planeSquareDist) * PI;

    return 1;
}
