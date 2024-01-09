#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int>& gain);

int main() {
    // vector<int> gain = {-5,1,5,0,-7};
    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    // vector<int> gain = {52,-91,72};

    cout << largestAltitude(gain) << endl;

    return 0;
}

int largestAltitude(vector<int>& gain) {
    int maxAlt = 0, tmpAlt = 0;

    for (size_t i = 0; i < gain.size(); i++) {
        tmpAlt += gain[i];
        maxAlt  = max(maxAlt, tmpAlt);
    }

    return maxAlt;
}
