#include <iostream>

using namespace std;

int totalStep(int x1, int y1, int x2, int y2);

int main() {
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << "Case " << i << ": " << totalStep(x1, y1, x2, y2) << endl;
    }

    return 0;
}

int totalStep(int x1, int y1, int x2, int y2) {
    int n1 = (x1 + y1 + 1);
    int n2 = (x2 + y2 + 1);

    int pos1 = n1 * (n1 + 1) / 2 - y1;
    int pos2 = n2 * (n2 + 1) / 2 - y2;

    return (pos2 - pos1);
}
