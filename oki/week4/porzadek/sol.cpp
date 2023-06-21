#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

const int N = 1000000 + 1;
char input[N];
bigint prefixR[N];
bigint prefixN[N];
bigint nieporzadki[N];

const char R = 'R';

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> input[i];

        if (input[i] == R) {
            prefixR[i] = 1 + prefixR[i - 1];
            prefixN[i] = prefixN[i - 1];
            nieporzadki[i] = nieporzadki[i - 1];
        }
        else {
            prefixN[i] = 1 + prefixN[i - 1];
            prefixR[i] = prefixR[i - 1];
            nieporzadki[i] = nieporzadki[i - 1] + prefixR[i];
        }
    }

    int a, b;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << nieporzadki[b] - ((prefixN[b] - prefixN[a - 1]) * prefixR[a - 1]) - nieporzadki[a - 1] << endl;
    }
}
