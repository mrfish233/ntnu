#pragma once

#include <queue>

class RecentCounter {
    std::queue<int> pings;

public:
    RecentCounter();
    int ping(int t);
};
