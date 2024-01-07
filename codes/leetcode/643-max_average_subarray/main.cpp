#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMaxAverage(vector<int>& nums, int k);

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout << "Max average: " << findMaxAverage(nums, k) << endl;

    return 0;
}

double findMaxAverage(vector<int>& nums, int k) {
    int subTotal = 0;

    for (size_t i = 0; i < size_t(k); i++) {
        subTotal += nums[i];
    }

    int maxTotal = subTotal;

    for (size_t i = k; i < nums.size(); i++) {
        subTotal += nums[i] - nums[i-k];
        maxTotal  = max(maxTotal, subTotal);
    }

    return (double) maxTotal / k;
}
