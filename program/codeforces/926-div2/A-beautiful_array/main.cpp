#include <iostream>
#include <vector>

using namespace std;

int maxBeauty(vector<int> array);

int main() {
    int n;
    cin >> n;

    while (n--) {
        int k;
        cin >> k;

        vector<int> array(k, 0);
        for (int i = 0; i < k; i++) {
            cin >> array[i];
        }

        cout << maxBeauty(array) << endl;
    }

    return 0;
}

int maxBeauty(vector<int> array) {
    int smallest = INT32_MAX, largest = 0;

    for (int i = 0; i < array.size(); i++) {
        if (smallest > array[i]) {
            smallest = array[i];
        }

        if (largest < array[i]) {
            largest = array[i];
        }
    }

    return largest - smallest;
}
