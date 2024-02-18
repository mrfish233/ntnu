#pragma once

#include <algorithm>
#include <vector>
#include <set>

// Using vector

// class SmallestInfiniteSet {
//     std::vector<int> nums;
// public:
//     SmallestInfiniteSet();
//     int popSmallest();
//     void addBack(int num);
// };

// =============================

// Using set

class SmallestInfiniteSet {
    std::set<int> nums;
public:
    SmallestInfiniteSet();
    int popSmallest();
    void addBack(int num);
};
