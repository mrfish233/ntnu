#include <iostream>

using namespace std;

int cardOrder(int n, int k);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        cout << cardOrder(n, k) << endl;
    }

    return 0;
}

int cardOrder(int n, int k) {
    int depth = 0, dist = 0;
    int tmp = n, sum = 0;

    while (sum + (tmp+1) / 2 < k && tmp > 0) {
        sum += (tmp+1) / 2;
        tmp /= 2;
        depth++;
    }

    dist = k - sum;

    // printf("%d, %d\n", dist, depth);

    int result = (1 << depth) + (1 << (depth + 1)) * (dist - 1);

    return result;
}
