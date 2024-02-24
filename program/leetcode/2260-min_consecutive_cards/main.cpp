#include <iostream>
#include <vector>
#include <map>

using namespace std;

int minimumCardPickup(vector<int>& cards);

int main() {
    int t;

    while (cin >> t) {
        vector<int> cards(t, 0);
        for (int i = 0; i < t; i++) {
            cin >> cards[i];
        }

        cout << minimumCardPickup(cards) << endl;
    }

    return 0;
}

int minimumCardPickup(vector<int>& cards) {
    map<int, int> pos;

    int i = 0, len = INT32_MAX;
    for (i = 0; i < cards.size(); i++) {
        int card = cards[i];

        if (pos.count(card)) {
            len = min(len, i - pos[card] + 1);
        }

        pos[card] = i;
    }

    if (len == INT32_MAX) {
        len = -1;
    }

    return len;
}
