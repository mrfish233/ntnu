#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int totalGCD(int num) {
    int total = 0;

    for (int i = 1; i < num; i++) {
        for (int j = i + 1; j <= num; j++) {
            total += gcd(i, j);
        }
    }

    return total;
}

int main() {
    int num = 0;

    while (cin >> num && num != 0) {
        cout << totalGCD(num) << endl;
    }

    return 0;
}
