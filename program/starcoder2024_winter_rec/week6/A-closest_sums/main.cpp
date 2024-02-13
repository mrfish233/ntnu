#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nearestNum(vector<int> nums, int target);

int main() {
    int n, m, cases = 0;

    while (cin >> n && n) {
        vector<int> nums(n, 0);
        vector<int> sums(n*(n-1)/2, 0);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sums[k++] = nums[i] + nums[j];
            }
        }

        sort(sums.begin(), sums.end());

        printf("Case %d:\n", ++cases);

        cin >> m;
        for (int i = 1; i <= m; i++) {
            int target;
            cin >> target;

            int result = nearestNum(sums, target);
            printf("Closest sum to %d is %d.\n", target, result);
        }
    }

    return 0;
}

int nearestNum(vector<int> nums, int target) {
    // cout << "[ ";
    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << ' ';
    // }
    // cout << "]\n";

    int i = 0;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) {
            break;
        }
    }

    if (nums[i] == target) {
        return target;
    } else if (i == 0 || abs(target - nums[i]) < abs(target - nums[i-1])) {
        return nums[i];
    } else {
        return nums[i-1];
    }
}
