#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000+7;
int prefixes[MAXN];
bool isBiquadratic[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < sqrt(MAXN); i++) {
        for (int j = 0; j < sqrt(MAXN); j++) {
            int idx = i * i + j * j;
            if (idx < MAXN)
                isBiquadratic[i * i + j * j] = true;
        }
    }

    prefixes[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        prefixes[i] = isBiquadratic[i] ? prefixes[i - 1] + 1 : prefixes[i - 1];
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefixes[b] - prefixes[a - 1] << endl;
    }
}
