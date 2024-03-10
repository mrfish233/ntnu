#include <bits/stdc++.h>

using namespace std;

int findPossibleValues(int a, int b, int l);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, l;
        cin >> a >> b >> l;
        cout << findPossibleValues(a, b, l) << "\n";
    }

    return 0;
}

int findPossibleValues(int a, int b, int l) {
    int x = 0, y = 0;

    int temp = a;
    while (temp <= l) {
        if (l % temp == 0) {
            x++;
        }

        temp *= a;
    }

    temp = b;
    while (temp <= l) {
        if (l % temp == 0) {
            y++;
        }

        temp *= b;
    }

    // printf("x:%d, y:%d\n", x, y);

    int count = 0;

    int tmpA = 1, tmpB;
    for (int i = 0; i <= x; i++) {
        if (a == b) {
            if (tmpA > l) {
                break;
            }

            if (l % tmpA == 0) {
                count++;
            }
        } else {
            tmpB = 1;
            for (int j = 0; j <= y; j++) {
                if ((tmpA * tmpB) > l) {
                    break;
                }

                if (l % (tmpA * tmpB) == 0) {
                    count++;
                }

                tmpB *= b;
            }
        }

        tmpA *= a;
    }

    return count;
}
