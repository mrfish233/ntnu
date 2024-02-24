#include <iostream>
#include <stack>
using namespace std;

long minProductDigit(int num);

int main() {
    int n, num = 0;
    cin >> n;

    while (n--) {
        cin >> num;
        cout << minProductDigit(num) << endl;
    }

    return 0;
}

long minProductDigit(int num) {
    if (num < 0 || num > 1000000000) {
        return -1;
    } else if (num == 1) {
        return 1;
    }

    stack<int> digit;

    for (int i = 9; i >= 2; i--) {
        if (num % i == 0) {
            digit.push(i);
            num /= i;
        }
    }

    if (num != 1) {
        return -1;
    }

    int result = 0;
    while (!digit.empty()) {
        result = result * 10 + digit.top();
        digit.pop();
    }

    return result;
}
