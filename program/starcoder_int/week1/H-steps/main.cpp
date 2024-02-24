#include <iostream>
using namespace std;

int steps(int start, int end);

int main() {
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int start, end;
        cin >> start >> end;
        cout << steps(start, end) << endl;
    }

    return 0;
}

int steps(int start, int end) {
    int step = 0, len = 1, total = end - start;

    while (len < total) {
        total -= len * 2;
        step += 2;
        len++;
    }

    if (total > 0) {
        step += 1;
    }

    return step;
}
