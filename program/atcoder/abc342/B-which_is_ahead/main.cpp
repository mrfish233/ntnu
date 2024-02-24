#include <iostream>
#include <vector>

using namespace std;

int findFront(vector<int> line, int a, int b);

int main() {
    int n, q;
    cin >> n;
    
    vector<int> line(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }

    cin >> q;

    int a, b;
    while (q--) {
        cin >> a >> b;
        cout << findFront(line, a, b) << endl;
    }

    return 0;
}

int findFront(vector<int> line, int a, int b) {
    int n = (int) line.size();

    int find = 0;

    for (int i = 0; i < n; i++) {
        if (line[i] == a) {
            find = a;
            break;
        } else if (line[i] == b) {
            find = b;
            break;
        }
    }

    return find;
}
