#include "mystring.h"

char *mystrchr(const char *s, int c) {
    if (s == NULL) {
        return NULL;
    }

    while (*s != 0) {
        if (*s == c) {
            return (char *) s; // cast away const
        }
        s++;
    }

    return NULL;
}

char *mystrrchr(const char *s, int c) {
    if (s == NULL) {
        return NULL;
    }

    int pos = -1, i = 0;

    while (*s != 0) {
        if (*s == c) {
            pos = i;
        }
        s++;
        i++;
    }

    if (pos == -1) {
        return NULL;
    }

    return (char *) (s - i + pos);
}

size_t mystrspn(const char *s, const char *accept) {
    if (s == NULL || accept == NULL) {
        return 0;
    }

    size_t count = 0;

    while (*s != 0) {
        if (mystrchr(accept, *s) == NULL) {
            return count;
        }
        s++;
        count++;
    }

    return count;
}

size_t mystrcspn(const char *s, const char *reject) {
    if (s == NULL || reject == NULL) {
        return 0;
    }

    size_t count = 0;

    while (*s != 0) {
        if (mystrchr(reject, *s) != NULL) {
            return count;
        }
        s++;
        count++;
    }

    return count;
}

char *mystrpbrk(const char *s, const char *accept) {
    if (s == NULL || accept == NULL) {
        return NULL;
    }

    while (*s != 0) {
        if (mystrchr(accept, *s) != NULL) {
            return (char *) s; // cast away const
        }
        s++;
    }

    return NULL;
}

char *mystrstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    while (*haystack != 0) {
        const char *h = haystack;
        const char *n = needle;

        while (*n != 0 && *h == *n) {
            h++;
            n++;
        }

        if (*n == 0) {
            return (char *) haystack; // cast away const
        }

        haystack++;
    }

    return NULL;
}

char *mystrtok(char *str, const char *delim) {
    static char *last = NULL;

    if (str != NULL) {
        last = str;
    } else if (last == NULL) {
        return NULL;
    }

    char *start = last;

    while (mystrchr(delim, *last) != NULL) {
        last++;
    }

    if (*last == 0) {
        last = NULL;
        return NULL;
    }

    start = last;

    while (mystrchr(delim, *last) == NULL && *last != 0) {
        last++;
    }

    if (*last != 0) {
        *last = 0;
        last++;
    }

    return start;
}
