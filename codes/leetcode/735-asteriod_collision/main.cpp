#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids);

void printVector(vector<int> nums) {
    cout << "[ ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << "]\n";
}

int main() {
    vector<int> asteroids = {5,10,-5};
    // vector<int> asteroids = {3,8,-8};
    // vector<int> asteroids = {10,2,-5};
    // vector<int> asteroids = {-2,-1,1,2};
    // vector<int> asteroids = {2,1,-1,-2};

    printVector(asteroidCollision(asteroids));

    return 0;
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;

    for (auto asteroid : asteroids) {
        while (true) {
            // Check if there's any asteroid

            if (result.empty()) {
                result.push_back(asteroid);
                break;
            }

            // The only way the asteriod will collide is the top
            // asteroid is moving right (positive) and current
            // asteroid is moving left (negative).

            int tail = *(result.end() - 1);

            if (!(tail > 0 && asteroid < 0)) {
                result.push_back(asteroid);
                break;
            }

            // Find which asteroid will be destroyed

            if (abs(tail) <= abs(asteroid)) {
                result.pop_back();
            }

            if (abs(tail) >= abs(asteroid)) {
                break;
            }
        }
    }

    return result;
}
