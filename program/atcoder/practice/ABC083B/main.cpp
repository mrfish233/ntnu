#include <iostream>
#include <vector>

using namespace std;

int sumOfDigits(int num);
int someSum(vector<int> sums, int n, int a, int b);

int main() {
    vector<int> sums(10000, 0);

    for (int i = 0; i < 10000; i++) {
        sums[i] = sumOfDigits(i + 1);
    }

    int n, a, b;
    while (cin >> n >> a >> b) {
        cout << someSum(sums, n, a, b) << endl;
    }

    return 0;
}

int sumOfDigits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int someSum(vector<int> sums, int n, int a, int b) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (a <= sums[i] && sums[i] <= b) {
            sum += (i + 1);
        }
    }

    return sum;
}

