#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    for (int i = 1; i <= k; i++) {
        cout << '1';
    }

    for (int i = 1; i <= k - 1; i++) {
        cout << '0';
    }

    cout << "\n";
}
