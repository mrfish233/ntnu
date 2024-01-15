#include <iostream>
#include <vector>

using namespace std;

int hartalDays(int days, vector<int> parties);

int main() {
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int days, party;
        cin >> days >> party;

        vector<int> parties(party, 0);
        for (int j = 0; j < party; j++) {
            cin >> parties[j];
        }

        cout << hartalDays(days, parties) << endl;
    }

    return 0;
}

int hartalDays(int days, vector<int> parties) {
    int total = 0;

    for (int i = 0; i < days; i++) {
        if (i % 7 == 5 || i % 7 == 6) {
            continue;
        }

        for (size_t j = 0; j < parties.size(); j++) {
            if ((i + 1) % parties[j] == 0) {
                total++;
                break;
            }
        }
    }

    return total;
}
