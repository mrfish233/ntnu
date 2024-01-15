#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums);

int main() {
    // vector<int> nums = {1,7,3,6,5,6};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {2,1,-1};
    vector<int> nums = {1,-1,2};

    cout << pivotIndex(nums) << endl;

    return 0;
}

int pivotIndex(vector<int>& nums) {
    int leftSum = 0, rightSum = 0;

    // Sum of whole vectors
    for (size_t i = 0; i < nums.size(); i++) {
        rightSum += nums[i];
    }

    // Loop through index, find index that leftSum is equal to rightSum
    for (size_t i = 0; i < nums.size(); i++) {
        rightSum -= nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}
