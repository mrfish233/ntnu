#include <iostream>
#include <vector>
using namespace std;

int numCost(vector<int> costs, int num, int base);

void cheapestBase(vector<int> costs, int num);

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        vector<int> costs(36, 0);

        for (int j = 0; j < 36; j++) {
            cin >> costs[j];
        }

        int k, num;
        cin >> k;

        if (i != 1) {
            cout << endl;
        }

        cout << "Case " << i << ":\n";
        while (k--) {
            cin >> num;
            cout << "Cheapest base(s) for number " << num << ": ";
            cheapestBase(costs, num);
        }
    }

    return 0;
}

int numCost(vector<int> costs, int num, int base) {
    if (num == 0) {
        return costs[num];
    }

    int cost = 0;

    while (num > 0) {
        cost += costs[num % base];
        num /= base;
    }

    return cost;
}

void cheapestBase(vector<int> costs, int num) {
    vector<int> baseCosts(37, 0);

    int minCost = INT32_MAX;

    for (int i = 2; i <= 36; i++) {
        baseCosts[i] = numCost(costs, num, i);
        minCost = min(minCost, baseCosts[i]);
    }

    bool print = false;

    for (int i = 2; i <= 36; i++) {
        if (baseCosts[i] == minCost) {
            if (print) {
                cout << " ";
            }

            cout << i;
            print = true;
        }
    }
    cout << endl;
}
