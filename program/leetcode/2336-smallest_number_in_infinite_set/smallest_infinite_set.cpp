#include "smallest_infinite_set.h"

// Using vector

// SmallestInfiniteSet::SmallestInfiniteSet() {}

// int SmallestInfiniteSet::popSmallest() {
//     if (nums.empty()) {
//         nums.push_back(1);
//         return 1;
//     }

//     int i = 0;
//     while (i < nums.size()) {
//         if (nums[i] != i + 1) {
//             break;
//         }

//         i++;
//     }

//     nums.push_back(i + 1);

//     sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
//         return a < b;
//     });

//     return i + 1;
// }

// void SmallestInfiniteSet::addBack(int num) {
//     int i = 0;

//     while (i < nums.size() && nums[i] <= num) {
//         if (nums[i] == num) {
//             nums.erase(nums.begin() + i);
//             return;
//         }

//         i++;
//     }
// }

// =========================================

SmallestInfiniteSet::SmallestInfiniteSet() {
    for (int i = 1; i <= 1000; i++) {
        nums.emplace(i);
    }
}

int SmallestInfiniteSet::popSmallest() {
    auto num = *nums.begin();
    nums.erase(nums.begin());

    return num;
}

void SmallestInfiniteSet::addBack(int num) {
    nums.emplace(num);
}
