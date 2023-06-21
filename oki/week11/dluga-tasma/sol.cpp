#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(2);

    int n;
    cin >> n;

    double minimum = DBL_MAX;
    for (int i = 1; i <= n; i++) {
        double x;
        cin >> x;
        minimum = min(minimum, x);
    }

    cout << minimum << endl;
}
