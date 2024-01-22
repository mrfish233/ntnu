#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void findBestPoint(vector<int> str, vector<int> ave, int k);

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int street, avenue, k;
        cin >> street >> avenue >> k;

        vector<int> str(k, 0), ave(k, 0);

        for (int j = 0; j < k; j++) {
            cin >> str[j] >> ave[j];
        }

        findBestPoint(str, ave, k);
    }

    return 0;
}

void findBestPoint(vector<int> str, vector<int> ave, int k) {
    sort(str.begin(), str.end());
    sort(ave.begin(), ave.end());

    cout << "(Street: " << str[(k-1)/2] << ", Avenue: " << ave[(k-1)/2] << ")\n";
}
