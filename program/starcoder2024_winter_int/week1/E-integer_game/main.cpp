#include <iostream>
#include <string>
using namespace std;

int removableDigit(string str);

int main() {
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;

        cout << "Case " << i << ": ";
        if (removableDigit(str) % 2) {
            cout << "S\n";
        } else {
            cout << "T\n";
        }
    }

    return 0;
}

int removableDigit(string str) {
    int mod3[3] = {0}, total = 0;

    for (char ch : str) {
        int digit = ch - '0';

        mod3[digit % 3]++;

        total += digit;
    }

    int remove = mod3[0];

    if (total % 3 != 0 && mod3[total % 3]) {
        remove += 1;
    }

    return remove;
}
