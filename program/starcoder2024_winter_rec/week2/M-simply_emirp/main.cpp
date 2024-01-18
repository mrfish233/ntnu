#include <iostream>
#include <cmath>

using namespace std;

int reverseNum(int num);
bool isPrime(int num);

int main() {
    int n = 0;

    while (cin >> n) {
        cout << n;
        if (isPrime(n)) {
            int rev = reverseNum(n);
            if (n != rev && isPrime(rev)) {
                cout << " is emirp." << endl;
            } else {
                cout << " is prime." << endl;
            }
        } else {
            cout << " is not prime." << endl;
        }
    }

    return 0;
}

int reverseNum(int num) {
    int rev = 0;

    while (num > 0) {
        rev  = rev * 10 + num % 10;
        num /= 10;
    }

    return rev;
}

bool isPrime(int num) {
    for (int i = 2; i < sqrt(num) + 1; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
