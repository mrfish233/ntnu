#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> returnedDay(vector<int> books);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> books(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> books[i];
        }

        vector<int> days = returnedDay(books);
        for (int i = 1; i <= n; i++) {
            cout << days[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<int> returnedDay(vector<int> books) {
    int n = (int) books.size();

    vector<int> days(n, 0);

    for (int i = 1; i < n; i++) {
        if (days[i] != 0) {
            continue;
        }

        int j = books[i];
        int loop = 1;

        while (i != j) {
            loop++;
            j = books[j];
        }

        j = books[i];
        while (i != j) {
            days[j] = loop;
            j = books[j];
        }

        days[j] = loop;
    }

    return days;
}

