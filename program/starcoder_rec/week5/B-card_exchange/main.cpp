#include <iostream>
#include <vector>
using namespace std;

void addCard(vector<int> &deck, int card);
int maxTrade(vector<int> deckA, vector<int> deckB);

int main() {
    int A, B, card;

    while (cin >> A >> B && A != 0 && B != 0) {
        vector<int> deckA, deckB;

        for (int i = 0; i < A; i++) {
            cin >> card;
            addCard(deckA, card);
        }

        for (int i = 0; i < B; i++) {
            cin >> card;
            addCard(deckB, card);
        }

        // cout << "[ ";
        // for (int i = 0; i < deckA.size(); i++) cout << deckA[i] << " ";
        // cout << "]\n";

        // cout << "[ ";
        // for (int i = 0; i < deckB.size(); i++) cout << deckB[i] << " ";
        // cout << "]\n";

        cout << maxTrade(deckA, deckB) << endl;
    }

    return 0;
}

void addCard(vector<int> &deck, int card) {
    if (deck.empty()) {
        deck.push_back(card);
        return;
    }

    auto lastCard = deck.end() - 1;

    if (*lastCard != card) {
        deck.push_back(card);
    }
}

int maxTrade(vector<int> deckA, vector<int> deckB) {
    auto cardA = deckA.begin();
    auto cardB = deckB.begin();

    int uniqueA = 0, uniqueB = 0;

    while (cardA != deckA.end() && cardB != deckB.end()) {
        if (*cardA < *cardB) {
            uniqueA++;
            cardA++;
        } else if (*cardA > *cardB) {
            uniqueB++;
            cardB++;
        } else {
            cardA++;
            cardB++;
        }
    }

    while (cardA != deckA.end()) {
        uniqueA++;
        cardA++;
    }

    while (cardB != deckB.end()) {
        uniqueB++;
        cardB++;
    }

    return min(uniqueA, uniqueB);
}
