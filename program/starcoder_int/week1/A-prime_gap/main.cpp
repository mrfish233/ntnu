#include <iostream>
using namespace std;

bool isPrime(int num);

int main() {
    int num = 0;

    while (cin >> num && num != 0) {
        if (isPrime(num)) {
            cout << 0 << endl;
            continue;
        }

        int head = num, tail = num;

        while (!isPrime(head)) {
            head--;
        }

        while (!isPrime(tail)) {
            tail++;
        }

        cout << (tail - head) << endl;
    }

    return 0;
}

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
