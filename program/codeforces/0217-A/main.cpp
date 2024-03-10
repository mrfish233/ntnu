#include <bits/stdc++.h>

using namespace std;

int minExtraDrift(vector<vector<int>> drifts);

int main() {
    int t;
    cin >> t;

    vector<vector<int>> drifts(t, vector<int>(2, 0));
    for (int i = 0; i < t; i++) {
        cin >> drifts[i][0] >> drifts[i][1];
    }

    printf("%d\n", minExtraDrift(drifts));

    return 0;
}

int minExtraDrift(vector<vector<int>> drifts) {
    int n = (int) drifts.size();

    for (int i = 0; i < n; i++) {
        printf("%d ", dsu[i]);
    }
    cout << "\n";

    set<int> result;

    for (int i = 0; i < n; i++) {
        if (!result.count(dsu[i])) {
            result.emplace(dsu[i]);
        }
    }

    return (int) result.size() - 1;
}
