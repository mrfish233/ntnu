#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define HOUR 0
#define MIN  1

vector<int> findTimeSpent(vector<int> startTime, vector<int> endTime);
double calculateCharge(vector<int> timeSpent, char step);

int main() {
    char step;
    string phoneNumber;
    vector<int> startTime(2, 0), endTime(2, 0);

    while (cin >> step && step != '#') {
        cin >> phoneNumber >> startTime[HOUR] >> startTime[MIN]>> endTime[HOUR] >> endTime[MIN];

        vector<int> timeSpent = findTimeSpent(startTime, endTime);
        double charge = calculateCharge(timeSpent, step);

        cout << "  " << phoneNumber;
        printf("%6d%6d%6d  %c%8.2lf\n", timeSpent[1], timeSpent[2], timeSpent[0], step, charge);
    }

    return 0;
}

vector<int> findTimeSpent(vector<int> startTime, vector<int> endTime) {
    vector<int> timeSpent(3, 0);
    const vector<int> schedule[4] = {
        {0, 480}, {480, 1080}, {1080, 1320}, {1320, 1440},
    };

    int startMin = startTime[HOUR] * 60 + startTime[MIN];
    int endMin   = endTime[HOUR]   * 60 + endTime[MIN];

    while (startMin != endMin) {
        for (int i = 0; i < 4; i++) {
            if (schedule[i][0] <= startMin && startMin < schedule[i][1]) {
                timeSpent[i%3]++;
                break;
            }
        }

        startMin++;

        if (startMin == 1440) {
            startMin = 0;
        }
    }

    return timeSpent;
}

double calculateCharge(vector<int> timeSpent, char step) {
    const double rate[5][3] = {
        {0.02, 0.10, 0.06},
        {0.05, 0.25, 0.15},
        {0.13, 0.53, 0.33},
        {0.17, 0.87, 0.47},
        {0.30, 1.44, 0.80},
    };

    int s = step - 'A';
    double charge = 0;

    for (int i = 0; i < 3; i++) {
        charge += timeSpent[i] * rate[s][i];
    }

    return charge;
}
