#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<int> ps;

    int n, m, p, t;
    cin >> n >> m >> p >> t;

    int a, b;
    int result = 0;

    for (int i = 1; i <= p; i++) {
        cin >> a >> b;
        ps.insert(b - (a - 1));
    }

    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        int x = b - (a - 1);
        if (ps.find(x) == ps.end()) 
            result++;
    }

    cout << result << "\n";
}
