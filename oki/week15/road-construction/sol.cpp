#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 7;
bool taken[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        taken[x] = true;
        taken[y] = true;
    }

    int center = -1;

    for (int i = 1; i <= n; i++) {
        if (taken[i] == false) {
            center = i;
            break;
        }
    }

    cout << n - 1 << "\n";

    for (int i = 1; i <= n; i++) {
        if (i == center)
            continue;
        cout << i << " " << center << "\n";
    }
}
