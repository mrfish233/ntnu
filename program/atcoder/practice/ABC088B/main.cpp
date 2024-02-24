#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findDifference(vector<int> nums);

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << findDifference(nums) << endl;
    }

    return 0;
}

int findDifference(vector<int> nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
        return a > b;
    });

    int alice = 0, bob = 0;

    for (int i = 0; i < (int) nums.size(); i++) {
        if (i % 2) {
            bob += nums[i];
        } else {
            alice += nums[i];
        }
    }

    return alice - bob;
}

