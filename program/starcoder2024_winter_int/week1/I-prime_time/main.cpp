#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isPrime(int num);
double eulerPrimePercentage(bool num[], int a, int b);

int main() {
    int a = 0, b = 0;

    bool num[10000] = {false};
    for (int i = 0; i <= 10000; i++) {
        num[i] = isPrime(i * i + i + 41);
    }

    while (cin >> a >> b) {
        double ans = eulerPrimePercentage(num, a, b) + 0.0000001;
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

double eulerPrimePercentage(bool num[], int a, int b) {
    int prime = 0;

    for (int i = a; i <= b; i++) {
        if (num[i]) {
            prime++;
        }
    }

    return 100.0 * prime / (b - a + 1);
}
