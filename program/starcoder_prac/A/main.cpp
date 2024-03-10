#include <bits/stdc++.h>
using namespace std;

double cal(int p, int a, int b, int c, int d, int k) {
    double price = 0;

    price = sin((double) a * k + b) + cos((double) c * k + d) + 2.0;
    price *= (double) p;

    return price;
}

double solve(vector<double> prices) {
    double temp = prices[0], res = 0;

    for (int i = 1; i < (int) prices.size(); i++) {
        if (prices[i] > temp) {
            temp = prices[i];
        } else if (res < temp - prices[i]) {
            res = temp - prices[i];
        }
    }

    return res;
}

int main() {
    int p, a, b, c, d, n;

    cin >> p >> a >> b >> c >> d >> n;

    vector<double> prices(n, 0);

    for (int i = 0; i < n; i++) {
        prices[i] = cal(p, a, b, c, d, i+1);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << prices[i] << " ";
    // }
    // cout << endl;

    printf("%lf\n", solve(prices));

    return 0;
}


