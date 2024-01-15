#include <iostream>
#include <vector>

using namespace std;

vector<int> digitCount(int num);

int main() {
    int cases = 0;
    cin >> cases;

    while (cases--) {
        int num = 0;
        cin >> num;

        vector<int> digit = digitCount(num);

        for (size_t i = 0; i < digit.size(); i++) {
            if (i != 0) {
                cout << ' ';
            }

            cout << digit[i];
        }
        cout << endl;
    }

    return 0;
}

vector<int> digitCount(int num) {
    vector<int> digit(10, 0);

    for (int i = 1; i <= num; i++) {
        int temp = i;

        while (temp > 0) {
            digit[temp % 10]++;
            temp /= 10;
        }
    }

    return digit;
}
