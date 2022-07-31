#include <bits/stdc++.h>

using namespace std;

const int MAX_PLAYERS = 50;

char s[MAX_PLAYERS];
int wonWith[MAX_PLAYERS];

void testCase();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0) {
        testCase();
    }
}

void testCase() {
    // lastTwo explanation
    // -2 means didn't win with anybody
    // -1 means this element will be changed when end of cycle is found
    // >= 0 means who win with whom
    int n;
    cin >> n;
    int twosCounter = 0;
    int lastTwo = -1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == '2') {
            wonWith[i] = lastTwo;
            lastTwo = i;
            twosCounter++;
        }
        else wonWith[i] = -2;
    }

    // it's possible to meet expectations only if there are at least
    // 3 twos or 0 twos
    if (twosCounter == 1 || twosCounter == 2) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (wonWith[i] != -1)
            continue;

        wonWith[i] = lastTwo;
        break;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 'X';
                continue;
            }
            if (wonWith[i] == j)
                cout << '+';
            else if (wonWith[j] == i)
                cout << '-';
            else cout << '=';
        }
        cout << endl;
    }
}
