#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void sortDNA(vector<pair<string, int>> &dna);

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n, m;
        cin >> n >> m;

        vector<pair<string, int>> dna;
        for (int j = 0; j < m; j++) {
            string str;
            cin >> str;

            dna.push_back(make_pair(str, 0));
        }

        sortDNA(dna);

        for (int j = 0; j < m; j++) {
            cout << dna[j].first << endl;
        }

        if (i != N) {
            cout << endl;
        }
    }

    return 0;
}

void sortDNA(vector<pair<string, int>> &dna) {
    for (int i = 0; i < (int) dna.size(); i++) {
        string tmp = dna[i].first;
        int val = 0;

        // for (int j = 0; j < (int) tmp.length(); j++) {
        //     for (int k = j + 1; k < (int) tmp.length(); k++) {
        //         if (tmp[j] > tmp[k]) {
        //             val++;
        //         }
        //     }
        // }

        vector<int> count(26, 0);
        for (int j = (int) tmp.length() - 1; j >= 0; j--) {

            int ch = tmp[j] - 'A';
            count[ch]++;

            for (int k = ch - 1; k >= 0; k--) {
                val += count[k];
            }

        }

        dna[i].second = val;
    }

    for (int i = 0; i < (int) dna.size(); i++) {
        for (int j = 0; j < (int) dna.size()-i-1; j++) {
            if (dna[j].second > dna[j+1].second) {
                swap(dna[j], dna[j+1]);
            }
        }
    }

    stable_sort(dna.begin(), dna.end(), [](pair<string, int> a, pair<string, int> b) -> bool {
        return a.second < b.second;
    });
}
