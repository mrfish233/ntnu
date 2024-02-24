#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numberOfGroups(vector<long> nums);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << numberOfGroups(nums) << endl;
    }

    return 0;
}

int numberOfGroups(vector<long> nums) {
    sort(nums.begin(), nums.end());

    int group = 0, head = 0, tail = nums.size() - 1;

    while (head < tail) {
        unsigned long sum = nums[head] + nums[tail];

        if (sum == INT32_MAX) {
            head++;
            tail--;
        } else if (sum > INT32_MAX) {
            tail--;
        } else {
            head++;
        }

        group++;
    }

    if (head == tail) {
        group++;
    }

    return group;
}
