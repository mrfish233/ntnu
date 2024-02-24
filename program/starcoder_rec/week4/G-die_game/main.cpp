#include <iostream>
#include <string>
using namespace std;

#define T 0
#define N 1
#define W 2

void rollDie(int face[], string dir);

int main() {
    int n;
    while (cin >> n && n != 0) {
        int face[3] = {1,2,3};
        string dir;

        for (int i = 0; i < n; i++) {
            cin >> dir;
            rollDie(face, dir);
        }

        cout << face[T] << endl;
    }

    return 0;
}

void rollDie(int face[], string dir) {
    int tmp = face[T];
    if (dir == "north") {
        face[T] = 7 - face[N];
        face[N] = tmp;
    } else if (dir == "south") {
        face[T] = face[N];
        face[N] = 7 - tmp;
    } else if (dir == "west") {
        face[T] = 7 - face[W];
        face[W] = tmp;
    } else if (dir == "east") {
        face[T] = face[W];
        face[W] = 7 - tmp;
    }
}
