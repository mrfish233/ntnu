#include <iostream>
#include <vector>

using namespace std;

int sumOfDigits(int num);

int main() {
    int t;
    cin >> t;

    vector<int> sum(200000, 0);

    for (int i = 0; i < 200000; i++) {
        sum[i] = sumOfDigits(i+1);
    }

    for (int i = 1; i < 200000; i++) {
        sum[i] += sum[i-1];
    }

    while (t--) {
        int n;
        cin >> n;
        cout << sum[n-1] << endl;
    }

    return 0;
}

int sumOfDigits(int num) {
    int sum = 0;

    while (num) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}
