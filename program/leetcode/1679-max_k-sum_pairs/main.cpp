#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxOperations(vector<int>& nums, int k);

int main() {
    vector<int> nums = {1,2,3,4};
    int k = 6;

    cout << "Max operations: " << maxOperations(nums, k) << endl;

    return 0;
}

int maxOperations(vector<int>& nums, int k) {
    // O(n^2) time complexity, O(n) space complexity

    // int operation = 0;
    // vector<bool> stat(nums.size(), false);

    // for (size_t i = 0; i < nums.size(); i++) {
    //     if (nums[i] > k) {
    //         continue;
    //     }

    //     for (size_t j = i + 1; j < nums.size(); j++) {
    //         if (nums[j] > k) {
    //             continue;
    //         }

    //         if (stat[i] == false && stat[j] == false && nums[i] + nums[j] == k) {
    //             stat[i] = true;
    //             stat[j] = true;
    //             operation++;
    //             break;
    //         }
    //     }
    // }

    // return operation;

    // ====================

    // O(nlog(n)) time complexity, O(1) space complexity

    int operation = 0, total = 0;
    size_t head = 0, tail = nums.size() - 1;

    sort(nums.begin(), nums.end());

    while (head < tail) {
        total = nums[head] + nums[tail];

        if (total < k) {
            head++;
        } else if (total > k) {
            tail--;
        } else {
            operation++;
            head++;
            tail--;
        }
    }

    return operation;
}
