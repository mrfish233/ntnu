#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> nums;
    while (cin >> n && n != 0) {
        nums.push_back(n);
    }

    nums.push_back(0);

    for (int i = (int) nums.size() - 1; i >= 0; i--) {
        printf("%d\n", nums[i]);
    }

    return 0;
}
