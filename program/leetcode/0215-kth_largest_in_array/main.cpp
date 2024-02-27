#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int> &nums, int k);

int main() {
    int n, k, cases = 0;

    while (cin >> n >> k) {
        vector<int> nums(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int find = findKthLargest(nums, k);
        printf("Case %d: %d\n", ++cases, find);
    }

    return 0;
}

int findKthLargest(vector<int> &nums, int k) {
    // Solve by using sort
    // sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
    //     return a > b;
    // });

    // return nums[k-1];

    // ===================================================

    // Solve by using priority queue
    // priority_queue<int, vector<int>, greater<int>> pq;

    // for (int i = 0; i < nums.size(); i++) {
    //     pq.push(nums[i]);

    //     if (pq.size() > k) {
    //         pq.pop();
    //     }
    // }

    // return pq.top();

    // ===================================================

    // Solve by using quick select
    int n = nums.size();
    int left = 0, right = n - 1;

    while (true) {
        int pos = left;
        int pivot = nums[right];

        for (int i = left; i < right; i++) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[pos++]);
            }
        }

        swap(nums[pos], nums[right]);

        if (pos == k - 1) {
            return nums[pos];
        } else if (pos < k - 1) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1;
}
