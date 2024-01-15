#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums);

void printVector(vector<int> &nums) {
    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> nums   = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);

    printVector(nums);
    printVector(result);

    return 0;
}

vector<int> productExceptSelf(vector<int>& nums) {
    // O(n^2) time complexity

    // vector<int> result(nums.size(), 1);

    // for (size_t i = 0; i < nums.size(); i++) {
    //     for (size_t j = 0; j < nums.size(); j++) {
    //         if (i != j) {
    //             result[i] *= nums[j];
    //         }
    //     }
    // }

    // ==========================

    // O(n) time complexity, O(n) space complexity

    vector<int> result(nums.size(), 1);

    for (size_t i = 0; i < nums.size() - 1; i++) {
        result[i + 1] = result[i] * nums[i];
    }

    int temp = 1;
    for (size_t i = nums.size() - 1; i > 0; i--) {
        temp *= nums[i];
        result[i - 1] *= temp;
    }

    return result;
}
