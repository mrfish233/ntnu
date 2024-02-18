#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef vector<string> vstr;
typedef unordered_map<string, vector<pair<string, double>>> mygraph;

double dfs(mygraph graph, string src, string dst, unordered_set<string> &visited);
vector<double> calcEquation(vector<vstr>& eqns, vector<double>& values, vector<vstr>& q);

int main() {
    int n, q;

    while (cin >> n >> q) {
        vector<vstr> eqns(n, vstr(2, ""));
        vector<vstr> queries(q, vstr(2, ""));
        vector<double> values(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> eqns[i][0] >> eqns[i][1] >> values[i];
        }

        for (int i = 0; i < q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }

        vector<double> calc = calcEquation(eqns, values, queries);

        cout << "[ ";
        for (int i = 0; i < q; i++) {
            cout << calc[i] << " ";
        }
        cout << "]\n";
    }

    return 0;
}

double dfs(mygraph graph, string src, string dst, unordered_set<string> &visited) {
    if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
        return -1;
    } else if (src == dst) {
        return 1;
    }

    for (auto node : graph[src]) {
        if (visited.count(node.first)) {
            continue;
        }

        visited.insert(node.first);

        double res = dfs(graph, node.first, dst, visited);

        if (res != -1) {
            return res * node.second;
        }
    }

    return -1;
}

vector<double> calcEquation(vector<vstr>& eqns, vector<double>& values, vector<vstr>& queries) {
    mygraph graph;
    vector<double> cal;

    for (int i = 0; i < (int) eqns.size(); i++) {
        vstr eqn = eqns[i];
        graph[eqn[0]].push_back(make_pair(eqn[1], values[i]));
        graph[eqn[1]].push_back(make_pair(eqn[0], 1.0 / values[i]));
    }

    for (auto query : queries) {
        unordered_set<string> visited;

        double res = dfs(graph, query[0], query[1], visited);
        cal.push_back(res);
    }

    return cal;
}
