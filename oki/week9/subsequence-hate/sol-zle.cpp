#include <bits/stdc++.h>

using namespace std;

const char ZERO = '0';
const char ONE = '1';

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

    int first0 = -1;
    int last0 = -1;
    int first1 = -1;
    int last1 = -1;
    
    for (int i = 1; i <= n; i++) {
        if (s[i] == ZERO) {
            first0 = first0 == -1 ? i : first0;
            last0 = i;
        }
        else if (s[i] == ONE) {
            first1 = first1 == -1 ? i : first1;
            last1 = i;
        }
    }

    if (first0 == -1) {
        first0 = INT_MIN;
        last0 = INT_MAX;
    }
    if (first1 == -1) {
        first1 = INT_MIN;
        last1 = INT_MAX;
    }

    // cout << first0 << " " << last0 << " " << first1 << " " << last1 << endl;

    int globMin = INT_MAX;
    int ctr0 = 0;
    int ctr1 = 0;
    
    for (int i = 1; i <= min(last0, last1); i++) {
        if (s[i] == ZERO) ctr0++;
        else if (s[i] == ONE) ctr1++;
    }

    globMin = min(ctr0, globMin);
    globMin = min(ctr1, globMin);

    ctr0 = 0;
    ctr1 = 0;

    for (int i = n; i >= max(first0, first1); i--) {
        if (s[i] == ZERO) ctr0++;
        else if (s[i] == ONE) ctr1++;
    }

    globMin = min(ctr0, globMin);
    globMin = min(ctr1, globMin);

    cout << globMin << endl;
}
