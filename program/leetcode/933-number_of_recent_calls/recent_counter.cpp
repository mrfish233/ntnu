#include "recent_counter.h"

RecentCounter::RecentCounter() {}

int RecentCounter::ping(int t) {
    pings.push(t);

    while (pings.front() < t - 3000) {
        pings.pop();
    }

    return pings.size();
}
