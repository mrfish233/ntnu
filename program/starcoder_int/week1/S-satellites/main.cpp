#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void findDistance(double dis, double deg, string type);

int main() {
    double dis, deg;
    string type;

    while (cin >> dis >> deg >> type) {
        findDistance(dis, deg, type);
    }

    return 0;
}

void findDistance(double dis, double deg, string type) {
    if (type == "min") {
        deg /= 60;
    }

    double rad = deg * M_PI / 180;
    rad = fmin(rad, 2 * M_PI - rad);

    double arc   = (dis + 6440) * rad;
    double chord = (dis + 6440) * 2 * sinl(rad / 2);

    cout << fixed << setprecision(6) << arc << " " << chord << endl;
}
