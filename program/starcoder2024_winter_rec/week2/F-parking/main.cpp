#include <iostream>
#include <vector>

using namespace std;

int minDistance(vector<int> stores);

int main() {
    int cases = 0;
    cin >> cases;

    while (cases--) {
        int num = 0, store = 0;
        cin >> num;

        vector<int> stores;
        for (int i = 0; i < num; i++) {
            cin >> store;
            stores.push_back(store);
        }

        cout << minDistance(stores) << endl;
    }

    return 0;
}

int minDistance(vector<int> stores) {
    int minStore = stores[0], maxStore = stores[0];

    for (auto store : stores) {
        if (minStore > store) {
            minStore = store;
        }

        if (maxStore < store) {
            maxStore = store;
        }
    }

    return (maxStore - minStore) * 2;
}
