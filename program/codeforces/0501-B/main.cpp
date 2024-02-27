#include <iostream>
#include <vector>
#include <string>

using namespace std;

void handleUser(vector<vector<string>> users);

int main() {
    int t;
    cin >> t;

    vector<vector<string>> users(t, vector<string>(2));

    for (int i = 0; i < t; i++) {
        cin >> users[i][0] >> users[i][1];
    }

    handleUser(users);

    return 0;
}

void handleUser(vector<vector<string>> users) {
    int n = (int) users.size();

    vector<bool> check(n, 0);
    vector<vector<string>> result;

    for (int i = 0; i < n; i++) {
        if (check[i]) {
            continue;
        }

        check[i] = true;

        string str1 = users[i][0];
        string str2 = users[i][1];

        for (int j = i + 1; j < n; j++) {
            if (check[j]) {
                continue;
            }

            if (str2 == users[j][0]) {
                str2 = users[j][1];
                check[j] = true;
            }
        }

        result.push_back({str1, str2});
    }

    cout << result.size() << "\n";

    for (int i = 0; i < (int) result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << "\n";
    }
}

