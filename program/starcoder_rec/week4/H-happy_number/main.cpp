#include <iostream>
#include <set>
using namespace std;

int squareDigitSum(int num);
bool isHappyNum(int num);

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        printf("Case #%d: %d is ", i, num);
        if (isHappyNum(num)) {
            printf("a Happy number.\n");
        } else {
            printf("an Unhappy number.\n");
        }
    }

    return 0;
}

int squareDigitSum(int num) {
    int sum = 0;

    while (num > 0) {
        int tmp = num % 10;
        sum += tmp * tmp;
        num /= 10;
    }

    return sum;
}

bool isHappyNum(int num) {
    set<int> prev;

    while (num != 1) {
        if (prev.find(num) != prev.end()) {
            return false;
        }

        prev.insert(num);
        num = squareDigitSum(num);
    }

    return true;
}
