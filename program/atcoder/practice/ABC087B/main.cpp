#include <iostream>
#include <vector>

using namespace std;

int calculateWays(int a, int b, int c, int total);

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        int total;
        cin >> total;

        cout << calculateWays(a, b, c, total) << endl;
    }

    return 0;
}

int calculateWays(int a, int b, int c, int total) {
    int count = 0;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                if (i * 500 + j * 100 + k * 50 == total) {
                    count++;
                }
            }
        }
    }

    return count;
}

