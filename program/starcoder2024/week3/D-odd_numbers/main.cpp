#include <iostream>

using namespace std;

long sumOddNumbers(long num);

int main() {
    long num;

    while (cin >> num) {
        cout << sumOddNumbers(num) << endl;
    }

    return 0;
}

long sumOddNumbers(long num) {
    long temp = (num - 3) / 2;

    return 15 + 6 * temp * (temp + 4);
}
