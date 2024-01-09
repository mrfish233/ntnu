#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);

void printVector(vector<int> &nums) {
    cout << "[ ";
    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums1 = {1,2,3}, nums2 = {2,4,6};
    // vector<int> nums1 = {1,2,3,3}, nums2 = {1,1,2,2};
    vector<vector<int>> result = findDifference(nums1, nums2);

    cout << "Result: " << endl;
    for (auto i : result) {
        printVector(i);
    }

    return 0;
}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    // vector<int> ans1, ans2;

    // sort(nums1.begin(), nums1.end());
    // sort(nums2.begin(), nums2.end());

    // size_t i = 0, j = 0;
    // int temp = 0;

    // while (i < nums1.size() && j < nums2.size()) {
    //     if (nums1[i] == nums2[j]) {
    //         temp = nums1[i];
    //     } else if (nums1[i] < nums2[j]) {
    //         temp = nums1[i];
    //         ans1.push_back(temp);
    //     } else {
    //         temp = nums2[j];
    //         ans2.push_back(temp);
    //     }

    //     while (i < nums1.size() && nums1[i] == temp) {
    //         i++;
    //     }

    //     while (j < nums2.size() && nums2[j] == temp) {
    //         j++;
    //     }
    // }

    // while (i < nums1.size()) {
    //     temp = nums1[i];
    //     ans1.push_back(temp);

    //     while (i < nums1.size() && nums1[i] == temp) {
    //         i++;
    //     }
    // }

    // while (j < nums2.size()) {
    //     temp = nums2[j];
    //     ans2.push_back(temp);

    //     while (j < nums2.size() && nums2[j] == temp) {
    //         j++;
    //     }
    // }

    // return {ans1, ans2};

    // ========================

    // Solution using unordered set

    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> ans1, ans2;

    for (auto num : set1) {
        if (set2.count(num) == 0) {
            ans1.push_back(num);
        }
    }

    for (auto num : set2) {
        if (set1.count(num) == 0) {
            ans2.push_back(num);
        }
    }

    return {ans1, ans2};
}
