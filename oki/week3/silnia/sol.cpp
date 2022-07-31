#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n >= 5) {
        cout << "0" << endl;
        return 0;
    }

    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
        result %= 10;
    }

    cout << result << endl;
}
