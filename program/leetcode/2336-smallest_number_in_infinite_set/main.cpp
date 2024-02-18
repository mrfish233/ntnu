#include <iostream>
#include "smallest_infinite_set.h"

using namespace std;

int main() {
    int n;
    SmallestInfiniteSet *obj = new SmallestInfiniteSet();

    while (cin >> n) {
        if (n == 1) {
            int pop = obj->popSmallest();
            printf("pop %d\n", pop);
        } else if (n == 2) {
            int num;
            cin >> num;

            obj->addBack(num);
        }
    }

    return 0;
}
