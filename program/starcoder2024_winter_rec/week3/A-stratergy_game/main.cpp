#include <iostream>
#include <vector>

using namespace std;

int main() {
    int player = 0, turn = 0;

    while (cin >> player >> turn) {
        vector<int> points(player, 0);

        for (int i = 0; i < player * turn; i++) {
            int point;
            cin >> point;

            points[i % player] += point;
        }

        int winner = 0;
        for (size_t i = 1; i < points.size(); i++) {
            if (points[winner] <= points[i]) {
                winner = i;
            }
        }

        cout << winner + 1 << endl;
    }

    return 0;
}
