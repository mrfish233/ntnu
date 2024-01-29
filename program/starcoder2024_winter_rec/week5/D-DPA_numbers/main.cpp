#include <iostream>
using namespace std;

int dpaNumber(int num);

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        int result = dpaNumber(num);

        if (result == 0) {
            cout << "perfect\n";
        } else if (result == -1) {
            cout << "deficient\n";
        } else {
            cout << "abundant\n";
        }
    }

    return 0;
}

int dpaNumber(int num) {
    int divisorSum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            divisorSum += i;
        }
    }

    if (divisorSum == num) {
        return 0;
    } else if (divisorSum < num) {
        return -1;
    } else {
        return 1;
    }
}
