#include <bits/stdc++.h>

using namespace std;

const char ZERO = '0';
const char ONE = '1';

const int MAXN = 1e3 + 7;
int prefix0[MAXN];
int prefix1[MAXN];

void testCase();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t-- > 0) {
        testCase();
    }
}

inline void testCase() {
    string s;
    cin >> s;

    int n = s.length();

    s.insert(0, 1, ' ');

    for (int i = 1; i <= n; i++) {
        prefix0[i] = prefix0[i - 1];
        prefix1[i] = prefix1[i - 1];
        if (s[i] == ZERO) prefix0[i]++;
        if (s[i] == ONE) prefix1[i]++;
    }

    int globalMin = INT_MAX;

    // i jest granicą pomiędzy cyfrą i-tą a (i-1)-szą "wskazującą" na i-tą cyfrę
    for (int i = 1; i <= n; i++) {
        int zerosOnRight = prefix0[n] - prefix0[i - 1];
        int onesOnRight = prefix1[n] - prefix1[i - 1];
        int zerosOnLeft = prefix0[i - 1];
        int onesOnLeft = prefix1[i - 1];

        int localMin = min(zerosOnLeft + onesOnRight, zerosOnRight + onesOnLeft);
        globalMin = min(localMin, globalMin);
    }
    
    cout << globalMin << endl;
}
