#include <iostream>
#include <cmath>

using namespace std;

void bookThief(int num);

int main() {
    while (1) {
        int num = 0;
        cin >> num;

        if (num == 0) {
            break;
        }

        bookThief(num);
    }

    return 0;
}

void bookThief(int num) {
    int forget = 0, total = 0;

    total  = ((int) sqrt(8 * num + 1) + 1) / 2;
    forget = total * (total + 1) / 2 - num;

    cout << forget << ' ' << total << endl;
}
