#include <iostream>
#include <vector>
#include "recent_counter.h"

using namespace std;

int main() {
    RecentCounter* obj = new RecentCounter();

    vector<int> pings = {1,100,3001,3002};

    for (auto i : pings) {
        cout << "Recent: " << obj->ping(i) << endl;
    }

    return 0;
}
