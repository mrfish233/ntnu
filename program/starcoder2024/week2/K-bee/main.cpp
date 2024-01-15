#include <iostream>

using namespace std;

void bee(long num);

int main() {
    long n = 0;
    while (cin >> n) {
        if (n == -1) {
            break;
        }

        bee(n);
    }

    return 0;
}

void bee(long num) {
    long i = 0, j = 1;

    while (num--) {
        long k = i + j + 1;
        i = j;
        j = k;
    }

    cout << i << ' ' << j << endl;
}
