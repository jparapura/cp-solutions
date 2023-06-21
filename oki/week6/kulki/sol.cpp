#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000+7;
const char BLACK = 'C';
const char WHITE = 'B';

char column[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int whiteCtr = 0;
    int blackCtr = 0;
    for (int i = 1; i <= N; i++) {
        cin >> column[i];
        // ustalamy których jest mniej na górze
        if (column[i] == BLACK) blackCtr++;
        else whiteCtr++;
    }
    
    char moreType, lessType;
    if (blackCtr > whiteCtr) {
        moreType = BLACK;
        lessType = WHITE;
    }
    else {
        moreType = WHITE;
        lessType = BLACK;
    }

    // zapamiętujemy indeksy tych, których jest mniej
    vector<int> upIdx;
    for (int i = 1; i <= N; i++) {
        if (column[i] == lessType) {
            upIdx.push_back(i);
        }
    }

    unsigned long long acc = 0;
    int upPtr = 0;
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        // te, których było mniej na górze są tymi, których jest więcej na dole
        if (c == moreType) {
            acc += abs(i - upIdx[upPtr++]) + 1;
        }
    }

    cout << acc << endl;
}
