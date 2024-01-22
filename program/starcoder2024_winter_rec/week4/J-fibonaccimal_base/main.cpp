#include <iostream>
#include <vector>
using namespace std;

vector<bool> fibBase(int num);

int main() {
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        vector<bool> fib = fibBase(num);

        cout << num << " = ";
        for (auto i : fib) {
            cout << i;
        }
        cout << " (fib)\n";
    }

    return 0;
}

vector<bool> fibBase(int num) {
    if (num == 0) {
        return {0};
    }

    vector<bool> fib;
    int f0 = 0, f1 = 1, f2;

    while (f0 + f1 <= num) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }

    while (f0 != 0) {
        if (num >= f1) {
            fib.push_back(true);
            num -= f1;
        } else {
            fib.push_back(false);
        }

        f2 = f1 - f0;
        f1 = f0;
        f0 = f2;
    }

    return fib;
}
