#include <stdio.h>
#include <stdint.h>

char letterDecode(char ch) {
    if (ch == 'A' || ch == 'B' || ch == 'C') {
        return '2';
    } else if (ch == 'D' || ch == 'E' || ch == 'F') {
        return '3';
    } else if (ch == 'G' || ch == 'H' || ch == 'I') {
        return '4';
    } else if (ch == 'J' || ch == 'K' || ch == 'L') {
        return '5';
    } else if (ch == 'M' || ch == 'N' || ch == 'O') {
        return '6';
    } else if (ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S') {
        return '7';
    } else if (ch == 'T' || ch == 'U' || ch == 'V') {
        return '8';
    } else if (ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z') {
        return '9';
    } else {
        return ch;
    }
}

int main() {
    char ch = 0;

    while (scanf("%c", &ch) != EOF) {
        printf("%c", letterDecode(ch));
    }

    return 0;
}
