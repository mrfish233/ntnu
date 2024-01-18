#include <iostream>
#include <string>

using namespace std;

int digitSum(int num);
int smallestGenerator(int num);

int main() {
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        cout << smallestGenerator(num) << endl;
    }

    return 0;
}

int digitSum(int num) {
    int total = num;

    while (num > 0) {
        total += num % 10;
        num /= 10;
    }

    return total;
}

int smallestGenerator(int num) {
    int generator = 0, temp = num;

    while (--temp > num - 50) {
        if(digitSum(temp) == num) {
            generator = temp;
        }
    }

    return generator;
}
