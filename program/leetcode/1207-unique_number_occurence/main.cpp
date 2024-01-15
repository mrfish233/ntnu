#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool uniqueOccurrences(vector<int>& arr);

int main() {
    vector<int> array = {-3,0,1,-3,1,1,1,-3,10,0};
    // vector<int> array = {1,2,2,1,1,3};
    // vector<int> array = {1,2};

    cout << uniqueOccurrences(array) << endl;

    return 0;
}

bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> occurMap;

    sort(arr.begin(), arr.end());

    int num = arr[0], count = 1;
    for (size_t i = 1; i <= arr.size(); i++) {
        if (i != arr.size() && arr[i] == num) {
            count++;
        } else {
            auto search = occurMap.find(count);
            if (search != occurMap.end()) {
                return false;
            }

            occurMap.insert({count, num});

            num = arr[i];
            count = 1;
        }
    }

    return true;
}
