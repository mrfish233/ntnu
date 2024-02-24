#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

bool isSquarePair(int a, int b);
int findSquarePair(vector<int> nums);

int main() {
    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << findSquarePair(nums) << "\n";

    return 0;
}

bool isSquarePair(int a, int b) {
    if (a == 0 || b == 0) {
        return true;
    }

    int factor = 2, check = 0;
    int maxFactor = (int) sqrt(max(a, b)) + 1;
    while (!(a == 1 && b == 1) || factor <= maxFactor) {
        while (a % factor == 0) {
            check++;
            a /= factor;
        }

        while (b % factor == 0) {
            check++;
            b /= factor;
        }

        if (check % 2) {
            return false;
        }

        factor++;
    }

    return true;
}

int findSquarePair(vector<int> nums) {
    int pair = 0;
    int n = (int) nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isSquarePair(nums[i], nums[j])) {
                pair++;
            }
        }
    }

    return pair;
}
