#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int l);

int main() {
    int t, n, l;

    cin >> t;

    while (t--) {
        cin >> n >> l;

        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        printf("%d\n", solve(nums, l));

        if (t != 0) {
            printf("\n");
        }
    }

    return 0;
}

int solve(vector<int> nums, int l) {
    sort(nums.begin(), nums.end());

    // for (auto num : nums) {
    //     cout << num << " ";
    // }
    // cout << endl;

    int head = 0, tail = (int) nums.size() - 1;
    int result = 0;

    while (head < tail) {
        if (nums[head] + nums[tail] <= l) {
            head++;
        }

        tail--;
        result++;
    }

    if (head == tail) {
        result++;
    }

    return result;
}

