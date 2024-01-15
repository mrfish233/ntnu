#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double minAngle(string time);

int main() {
    while (1) {
        string time;
        cin >> time;

        if (time == "0:00") {
            break;
        }

        double angle = minAngle(time);

        cout << fixed << setprecision(3) << angle << endl;
    }

    return 0;
}

double minAngle(string time) {
    int hour = 0, minute = 0;

    int isHour = 1;
    for (size_t i = 0; i < time.length(); i++) {
        if (time[i] == ':') {
            isHour = 0;
        } else if (isHour) {
            hour = hour * 10 + (time[i] - '0');
        } else {
            minute = minute * 10 + (time[i] - '0');
        }
    }

    double hourAngle   = hour * 30.0 + minute / 2.0;
    double minuteAngle = minute * 6.0;

    double angle = fabs(hourAngle - minuteAngle);
    angle = min(angle, 360 - angle);

    return angle;
}
