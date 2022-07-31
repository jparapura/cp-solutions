#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
int pyramid[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    
    int maxCapacity = 1 << n - 1;
    pyramid[0][0] = maxCapacity * t;
    int fullCups = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (pyramid[i][j] > maxCapacity) {
                int overflowPerCup = (pyramid[i][j] - maxCapacity) >> 1;
                pyramid[i][j] = maxCapacity;
                pyramid[i + 1][j] += overflowPerCup;
                pyramid[i + 1][j + 1] += overflowPerCup;
            }

            if (pyramid[i][j] == maxCapacity)
                fullCups++;
        }
    }

    cout << fullCups << endl;
}
