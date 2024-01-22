#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMarblePos(vector<int> marbles, int num);

int main() {
    int m, n, cases = 0;

    while (cin >> m >> n && m != 0 && n != 0) {
        vector<int> marbles(m, 0);
        int num;

        for (int i = 0; i < m; i++) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        printf("CASE# %d:\n", ++cases);
        for (int i = 0; i < n; i++) {
            cin >> num;

            int pos = findMarblePos(marbles, num);
            if (pos) {
                printf("%d found at %d\n", num, pos);
            } else {
                printf("%d not found\n", num);
            }
        }
    }

    return 0;
}

int findMarblePos(vector<int> marbles, int num) {
    for (int i = 0; i < marbles.size(); i++) {
        if (marbles[i] == num) {
            return i + 1;
        } else if (marbles[i] > num) {
            break;
        }
    }

    return 0;
}
