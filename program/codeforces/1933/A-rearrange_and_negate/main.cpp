#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int> nums);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << maxSum(nums) << "\n";
    }

    return 0;
}

int maxSum(vector<int> nums) {
    int sum = 0;
    int n = (int) nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            sum -= nums[i];
        } else {
            sum += nums[i];
        }
    }

    return sum;
}
