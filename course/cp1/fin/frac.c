#include "frac.h"

static int64_t gcd(int32_t x, int32_t y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;

    if (y == 0) {
        return x;
    }

    return gcd(y, x % y);
}

int32_t frac_add( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ) {
    if (x == NULL || y == NULL || b == 0 || d == 0) {
        return -1;
    }

    int64_t numerator = 0, denominator = 0;

    numerator   = a * d + b * c;
    denominator = b * d;

    int64_t factor = gcd(numerator, denominator);
    if (factor != 1) {
        numerator /= factor;
        denominator /= factor;
    }

    if (numerator > INT32_MAX || numerator < INT32_MIN || denominator > INT32_MAX || denominator < INT32_MIN) {
        return -1;
    }

    if (numerator > 0 && denominator < 0) {
        numerator   = -numerator;
        denominator = -denominator;
    }

    if (numerator == 0) {
        denominator = 1;
    }

    *x = numerator;
    *y = denominator;

    return 0;
}

int32_t frac_del( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ) {
    return frac_add(x, y, a, b, -c, d);
}

int32_t frac_mul( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ) {
    if (x == NULL || y == NULL || b == 0 || d == 0) {
        return -1;
    }

    int64_t numerator = 0, denominator = 0;

    numerator   = a * c;
    denominator = b * d;

    int64_t factor = gcd(numerator, denominator);
    if (factor != 1) {
        numerator /= factor;
        denominator /= factor;
    }

    if (numerator > INT32_MAX || numerator < INT32_MIN || denominator > INT32_MAX || denominator < INT32_MIN) {
        return -1;
    }

    if (numerator > 0 && denominator < 0) {
        numerator   = -numerator;
        denominator = -denominator;
    }

    if (numerator == 0) {
        denominator = 1;
    }

    *x = numerator;
    *y = denominator;

    return 0;
}

int32_t frac_div( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ) {
    return frac_mul(x, y, a, b, d, c);
}
