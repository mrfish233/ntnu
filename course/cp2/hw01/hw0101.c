#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mystring.h"

#include <string.h>

int main() {
    char *str1 = "this is a string 12345.";
    char *str2 = malloc(10 * sizeof(char));
    char *str3 = NULL;
    char *str4 = "";
    char str5;
    char str6 = 's';

    char c1 = 's';

    printf("str1: %s\n", mystrchr(str1, c1));
    printf("str2: %s\n", mystrchr(str2, c1));
    printf("str3: %s\n", mystrchr(str3, c1));
    printf("str4: %s\n", mystrchr(str4, c1));
    printf("str5: %s\n", mystrchr(&str5, c1));
    printf("str6: %s\n", mystrchr(&str6, c1));
    printf("str7: %s\n", mystrchr("a string 123", c1));

    printf("\n");

    printf("str1: %s\n", mystrrchr(str1, c1));
    printf("str2: %s\n", mystrrchr(str2, c1));
    printf("str3: %s\n", mystrrchr(str3, c1));
    printf("str4: %s\n", mystrrchr(str4, c1));
    printf("str5: %s\n", mystrrchr(&str5, c1));
    printf("str6: %s\n", mystrrchr(&str6, c1));
    printf("str7: %s\n", mystrrchr("a string 123", c1));

    printf("\n");

    char *accept = "abcdefghijklmnopqrstuvwxyz";
    char *accept2 = "aeiou";
    char *reject = "1234567890";

    printf("str1: %ld\n", mystrspn(str1, accept));
    printf("str2: %ld\n", mystrspn(str2, accept));
    printf("str3: %ld\n", mystrspn(str3, accept));
    printf("str4: %ld\n", mystrspn(str4, accept));
    printf("str5: %ld\n", mystrspn(&str5, accept));
    printf("str6: %ld\n", mystrspn(&str6, accept));
    printf("str7: %ld\n", mystrspn("a string 123", accept));

    printf("\n");

    printf("str1: %ld\n", mystrcspn(str1, reject));
    printf("str2: %ld\n", mystrcspn(str2, reject));
    printf("str3: %ld\n", mystrcspn(str3, reject));
    printf("str4: %ld\n", mystrcspn(str4, reject));
    printf("str5: %ld\n", mystrcspn(&str5, reject));
    printf("str6: %ld\n", mystrcspn(&str6, reject));
    printf("str7: %ld\n", mystrcspn("a string 123", reject));

    printf("\n");

    printf("str1: %c %s\n", *(mystrpbrk(str1, accept2)), mystrpbrk(str1, accept2));
    printf("str7: %c %s\n", *(mystrpbrk("a string 123", accept2)), mystrpbrk("a string 123", accept2));

    printf("\n");

    printf("str1: %c %s\n", *(strpbrk(str1, accept2)), strpbrk(str1, accept2));
    printf("str7: %c %s\n", *(strpbrk("a string 123", accept2)), strpbrk("a string 123", accept2));

    printf("\n");

    char *needle1 = "is";
    char *needle2 = malloc(10 * sizeof(char));
    char *needle3 = NULL;
    char *needle4 = "";
    char needle5;
    char needle6 = 's';

    printf("str1 n1: %s\n", mystrstr(str1, needle1));
    printf("str1 n2: %s\n", mystrstr(str1, needle2));
    printf("str1 n3: %s\n", mystrstr(str1, needle3));
    printf("str1 n4: %s\n", mystrstr(str1, needle4));
    printf("str1 n5: %s\n", mystrstr(str1, &needle5));
    printf("str1 n6: %s\n", mystrstr(str1, &needle6));
    printf("str1 n7: %s\n", mystrstr(str1, "str"));

    printf("str1 n1: %s\n", strstr(str1, needle1));
    printf("str1 n2: %s\n", strstr(str1, needle2));
    // printf("str1 n3: %s\n", strstr(str1, needle3));
    printf("str1 n4: %s\n", strstr(str1, needle4));
    printf("str1 n5: %s\n", strstr(str1, &needle5));
    printf("str1 n6: %s\n", strstr(str1, &needle6));
    printf("str1 n7: %s\n", strstr(str1, "str"));

    printf("\n");

    printf("str1 n1: %s\n", strstr(str1, needle1));
    printf("str2 n1: %s\n", strstr(str2, needle1));
    // printf("str3 n1: %s\n", strstr(str3, needle1)); // Segmentation fault
    printf("str4 n1: %s\n", strstr(str4, needle1));
    printf("str5 n1: %s\n", strstr(&str5, needle1));
    printf("str6 n1: %s\n", strstr(&str6, needle1));
    printf("str7 n1: %s\n", strstr("a string 123", needle1));

    printf("str1 n1: %s\n", mystrstr(str1, needle1));
    printf("str2 n1: %s\n", mystrstr(str2, needle1));
    // printf("str3 n1: %s\n", mystrstr(str3, needle1)); // Segmentation fault
    printf("str4 n1: %s\n", mystrstr(str4, needle1));
    printf("str5 n1: %s\n", mystrstr(&str5, needle1));
    printf("str6 n1: %s\n", mystrstr(&str6, needle1));
    printf("str7 n1: %s\n", mystrstr("a string 123", needle1));

    printf("\n");

    char m_str1[] = "this is a string 12345.";
    char m_str2[] = "";
    char m_str3 = 'a';

    char *delim = "is";

    char *token1 = mystrtok(m_str1, delim);

    printf("token1: ");
    while (token1 != NULL) {
        printf("%s_", token1);
        token1 = mystrtok(NULL, delim);
    }
    printf("\n");

    char *token2 = mystrtok(m_str2, delim);

    printf("token2: ");
    while (token2 != NULL) {
        printf("%s_", token2);
        token2 = mystrtok(NULL, delim);
    }
    printf("\n");

    char *token3 = mystrtok(&m_str3, delim);

    printf("token3: ");
    while (token3 != NULL) {
        printf("%s_", token3);
        token3 = mystrtok(NULL, delim);
    }
    printf("\n");

    return 0;
}
