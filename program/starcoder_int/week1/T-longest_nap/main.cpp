#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int convertTime(string time);
void findLongestNap(vector<int> start, vector<int> stop);

int main() {
    int n, i = 0;

    while (cin >> n) {
        vector<int> start(n, 0), stop(n, 0);

        for (int j = 0; j < n; j++) {
            string startTime, endTime, desc;
            cin >> startTime >> endTime;
            getline(cin, desc);

            start[j] = convertTime(startTime);
            stop[j]  = convertTime(endTime);
            // cout << start[j] << "--" << stop[j] << "--" << desc << endl;
        }

        cout << "Day #" << ++i << ": ";
        findLongestNap(start, stop);
    }

    return 0;
}

int convertTime(string time) {
    int min = 0, tmp = 0;
    for (char ch : time) {
        if (isdigit(ch)) {
            tmp = tmp * 10 + ch - '0';
        } else {
            min = tmp * 60;
            tmp = 0;
        }
    }

    min += tmp;

    return min;
}

void findLongestNap(vector<int> start, vector<int> stop) {
    sort(start.begin(), start.end());
    sort(stop.begin(),  stop.end());

    vector<vector<int>> nap;

    int lastStop = 600;
    for (size_t i = 0; i < start.size(); i++) {
        if (start[i] != lastStop) {
            nap.push_back({ lastStop, start[i] - lastStop });
        }

        lastStop = stop[i];
    }

    if (lastStop != 1080) {
        nap.push_back({ lastStop, 1080 - lastStop });
    }

    size_t result = 0;
    for (size_t i = 1; i < nap.size(); i++) {
        if (nap[i][1] > nap[result][1]) {
            result = i;
        }
    }

    int hh = nap[result][0] / 60, mm = nap[result][0] % 60;
    int hour = nap[result][1] / 60, min = nap[result][1] % 60;

    printf("the longest nap starts at %d:%02d and will last for ", hh, mm);
    if (hour > 0) printf("%d hours and ", hour);
    printf("%d minutes.\n", min);

    // cout << "the longest nap starts at " <<  << " and will last for ";
}
