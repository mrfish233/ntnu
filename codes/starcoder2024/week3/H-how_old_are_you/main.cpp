#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DAY   0
#define MONTH 1
#define YEAR  2

vector<int> convertDate(string date);
string checkBirthDate(string current, string birth);

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string current, birth;
        cin >> current >> birth;

        cout << "Case #" << i << ": " << checkBirthDate(current, birth) << endl;
    }

    return 0;
}

vector<int> convertDate(string date) {
    vector<int> result;

    string day   = date.substr(0, 2);
    string month = date.substr(3, 2);
    string year  = date.substr(6, 4);

    result.push_back(stoi(day));
    result.push_back(stoi(month));
    result.push_back(stoi(year));

    return result;
}

string checkBirthDate(string currentDate, string birthDate) {
    vector<int> curr  = convertDate(currentDate);
    vector<int> birth = convertDate(birthDate);

    if ((curr[YEAR] < birth[YEAR]) ||
        (curr[YEAR] == birth[YEAR] && curr[MONTH] < birth[MONTH]) ||
        (curr[YEAR] == birth[YEAR] && curr[MONTH] == birth[MONTH] && curr[DAY] < birth[DAY])) {
        return "Invalid birth date";
    }

    int age = curr[YEAR] - birth[YEAR];

    if ((curr[MONTH] < birth[MONTH]) ||
        (curr[MONTH] == birth[MONTH] && curr[DAY] < birth[DAY])) {
        age--;
    }

    if (age > 130) {
        return "Check birth date";
    }

    return to_string(age);
};
