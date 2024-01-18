#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAGENTA 0
#define YELLOW  1
#define CYAN    2

void checkPaint(vector<int> color, string pixel);

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        vector<int> color(3, 0);
        string pixel;
        cin >> color[MAGENTA] >> color[YELLOW] >> color[CYAN] >> pixel;

        checkPaint(color, pixel);
    }

    return 0;
}

void checkPaint(vector<int> color, string pixel) {
    for (auto p : pixel) {
        if (p == 'M' || p == 'R' || p == 'V' || p == 'B') {
            color[MAGENTA]--;
        }

        if (p == 'Y' || p == 'R' || p == 'G' || p == 'B') {
            color[YELLOW]--;
        }

        if (p == 'C' || p == 'V' || p == 'G' || p == 'B') {
            color[CYAN]--;
        }

        if (color[MAGENTA] < 0 || color[YELLOW] < 0 || color[CYAN] < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES "
         << color[MAGENTA] << " "
         << color[YELLOW] << " "
         << color[CYAN] << "\n";
}
