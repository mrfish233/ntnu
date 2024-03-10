#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b);
bool canContinualMod(vector<int> nums);

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

        if (canContinualMod(nums)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

bool canContinualMod(vector<int> nums) {
    int div = nums[0];
    int n = (int) nums.size();

    for (int i = 1; i < n; i++) {
        div = gcd(div, nums[i]);
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == div) {
            count++;
        }

        if (count == 2) {
            return false;
        }
    }

    return true;
}
