#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;

vector<int> edges[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end());

        if (edges[i].empty()) {
            cout << "Wiewior sam!\n";
            continue;
        }

        for (int x : edges[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
