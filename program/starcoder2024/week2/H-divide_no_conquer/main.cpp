#include <iostream>
#include <vector>

using namespace std;

void divide(int n, int m);

int main() {
    int n = 0, m = 0;

    while (cin >> n >> m) {
        divide(n, m);
    }

    return 0;
}

void divide(int n, int m) {
    if (n == 0 || m == 0 || n == 1 || m == 1) {
        cout << "Boring!" << endl;
        return;
    }

    vector<int> nums;

    nums.push_back(n);
    while (n > 1) {
        if (n % m != 0) {
            cout << "Boring!" << endl;
            return;
        }

        n /= m;
        nums.push_back(n);
    }

    for (size_t i = 0; i < nums.size(); i++) {
        if (i != 0) {
            cout << " ";
        }

        cout << nums[i];
    }
    cout << endl;

    return;
}
