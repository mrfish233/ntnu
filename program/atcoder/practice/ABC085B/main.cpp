#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findLayers(vector<int> nums);

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << findLayers(nums) << endl;
    }

    return 0;
}

int findLayers(vector<int> nums) {
    sort(nums.begin(), nums.end());

    int curr = 0, layer = 0;
    int n = (int) nums.size();

    for (int i = 0; i < n; i++) {
        if (curr < nums[i]) {
            curr = nums[i];
            layer++;
        }
    }

    return layer;
}

