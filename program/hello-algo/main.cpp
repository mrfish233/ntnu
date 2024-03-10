#include <iostream>
#include "src/linked_list.h"
#include "src/array_hash.h"

using namespace std;

void hashMapTest();

int main() {
    hashMapTest();

    return 0;
}

void hashMapTest() {
    ArrayHash *hashMap = new ArrayHash();

    hashMap->put(12345, "Adam");
    hashMap->put(12234, "Ben");
    hashMap->put(11399, "Charlie");
    hashMap->put(31372, "Daniel");
    hashMap->put(21258, "Evan");

    cout << "12345: " << hashMap->get(12345) << "\n";
    cout << "12346: " << hashMap->get(12346) << "\n";

    vector<string> names = hashMap->getValues();

    cout << "Lists: ";
    for (auto name : names) {
        cout << name << ' ';
    }
    cout << endl;
}
