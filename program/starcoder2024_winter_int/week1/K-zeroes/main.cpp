#include <iostream>
using namespace std;

long factorialZero(long low, long high);

int main() {
    long low, high;

    while (cin >> low >> high && low != 0 && high != 0) {
        cout << factorialZero(low, high) << endl;
    }

    return 0;
}

long factorialZero(long low, long high) {
    return high / 5 - low / 5 + 1;
}
