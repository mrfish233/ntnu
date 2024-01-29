#include <iostream>
using namespace std;

int minTries(int key, int house);

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int key, house;
        cin >> key >> house;

        cout << minTries(key, house) << endl;
    }

    return 0;
}

int minTries(int key, int house) {
    int tries = 0;

    if (house > key) {
        tries += (house - key) * key;
        house = key;
    }

    tries += key * (key - 1) / 2;

    return tries;
}
