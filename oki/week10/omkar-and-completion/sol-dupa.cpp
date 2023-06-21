#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 7;
bool els[MAXN];

void testCase();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 1e3; i++) {
        if (els[i]) {
            continue;
        }
        for (int j = 1; j <= i; j++) {
            els[i + j] = true;
        }
    }

    int t;
    cin >> t;
    while (t-- > 0) {
        testCase();
    }
}

void testCase() {
    int n;
    cin >> n;
    int found = 0;
    for (int i = 1; i <= 1e3; i++) {
        if (els[i] == false) {
            found++;
            cout << i << " ";
        }
        if (found == n) 
            break;
    }
    cout << endl;
}
