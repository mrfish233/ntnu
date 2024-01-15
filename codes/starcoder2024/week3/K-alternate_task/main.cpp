#include <iostream>

using namespace std;

int factorSum(int num);
int largestFactorSum(int sum);

int main() {
    int num = 0, i = 0;

    while (cin >> num && num != 0) {
        cout << "Case " << ++i << ": " << largestFactorSum(num) << endl;
    }

    return 0;
}

int factorSum(int num) {
    int sum = num, temp = 1;

    while (temp * 2 <= num) {
        if (num % temp == 0) {
            sum += temp;
        }

        temp++;
    }

    return sum;
}

int largestFactorSum(int sum) {
    if (sum == 1) {
        return 1;
    }

    int num = 1, largest = -1;

    while (num < sum) {
        if (factorSum(num) == sum) {
            largest = num;
        }

        num++;
    }

    return largest;
}
