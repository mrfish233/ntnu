#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n);

int main() {
    vector<int> flowerbed{0, 0, 0, 0, 0};
    int n = 3;

    cout << canPlaceFlowers(flowerbed, n) << endl;

    return 0;
}

bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    if (n == 0) {
        return true;
    }

    for (size_t i = 0; i < flowerbed.size(); i++) {
        if ((flowerbed[i] == 0) &&
            (i == 0 || flowerbed[i - 1] == 0) &&
            (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            n--;

            if (n == 0) {
                return true;
            }
        }
    }

    return false;
}
