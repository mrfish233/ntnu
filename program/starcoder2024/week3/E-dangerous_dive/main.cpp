#include <iostream>
#include <vector>

using namespace std;

void remainingVolunteer(vector<bool> volunteers, int left);

int main() {
    int num = 0, left = 0;

    while (cin >> num >> left) {
        vector<bool> volunteers(num, 0);

        int vol = 0;
        for(int i = 0; i < left; i++) {
            cin >> vol;
            volunteers[vol-1] = true;
        }

        remainingVolunteer(volunteers, left);
    }

    return 0;
}

void remainingVolunteer(vector<bool> volunteers, int left) {
    if (volunteers.size() == (size_t) left) {
        cout << "*\n";
        return;
    }

    for (size_t i = 0; i < volunteers.size(); i++) {
        if (!volunteers[i]) {
            cout << i + 1 << " ";
            left++;
        }

        if (volunteers.size() == (size_t) left) {
            break;
        }
    }
    cout << endl;
}
