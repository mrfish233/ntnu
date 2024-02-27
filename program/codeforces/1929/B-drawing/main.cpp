#include <iostream>
#include <string>

using namespace std;

long minCells(long n, long k);

int main() {
    long t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        cout << minCells(n, k) << endl;
    }

    return 0;
}

long minCells(long n, long k) {
    long two;

    if (n <= 2) {
        two = n;
    } else {
        two = n * 2 - 2;
    }

    if (two * 2 >= k) {
        return (k + 1) / 2;
    }

    return (k - two * 2) + two;
}
