#include <iostream>
#include <vector>
using namespace std;

int turnDegree(int from, int to);

int main() {
    int a, b, c, d;

    while (cin >> a >> b >> c >> d && (a || b || c || d)) {
        int total = 0;

        total += 1080;
		total += turnDegree(a,b);
		total += turnDegree(c,b);
		total += turnDegree(c,d);

		printf("%d\n", total);
    }

    return 0;
}

int turnDegree(int from, int to) {
    return 9 * ((to > from) ? (40 + from - to) : (from - to));
}
