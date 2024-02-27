#include <iostream>
#include <vector>

using namespace std;

bool canSurvive(long k, vector<long> health, vector<long> pos);

int main() {
    long t;
    cin >> t;

    while (t--) {
        long n, k;
        cin >> n >> k;

        vector<long> health(n, 0), pos(n, 0);

        for (long i = 0; i < n; i++) {
            cin >> health[i];
        }

        for (long i = 0; i < n; i++) {
            cin >> pos[i];
        }

        if (canSurvive(k, health, pos)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

bool canSurvive(long k, vector<long> health, vector<long> pos) {
    long n = pos.size();

    vector<long> check(n, 0);

    for (int i = 0; i < n; i++) {
        int tmp = abs(pos[i]) - 1;

        check[tmp] += health[i];
    }

    long bullet = 0;

    for (int i = 0; i < n; i++) {
        bullet += k - check[i];

        if (bullet < 0) {
            return false;
        }
    }

    return true;
}
