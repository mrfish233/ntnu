#include <iostream>
#include <vector>

using namespace std;


int p = 0;
int guess(int num);
int guessNumber(int n);

int main() {
    int n, cases = 0;

    while (cin >> n >> p) {
        printf("Case %d: %d\n", ++cases, guessNumber(n));
    }

    return 0;
}

int guess(int num) {
    if (num == p) {
        return 0;
    } else if (num < p) {
        return 1;
    } else {
        return -1;
    }
}

int guessNumber(int n) {
    long left = 1, right = n;

    while (left <= right) {
        long pick = (left + right) / 2;
        long test = guess(pick);

        if (!test) {
            return pick;
        } else if (test == 1) {
            left = pick + 1;
        } else {
            right = pick - 1;
        }
    }

    return -1;
}
