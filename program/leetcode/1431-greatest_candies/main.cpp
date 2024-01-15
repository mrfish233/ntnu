#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies);

int main() {
    vector<int> candies{3, 3, 5, 1, 2};
    int extra = 2;

    for (auto i : kidsWithCandies(candies, extra)) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int most = *max_element(begin(candies), end(candies));

    vector<bool> result;
    for (auto i : candies) {
        result.push_back(i + extraCandies >= most);
    }

    return result;
}
