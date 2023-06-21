#include <bits/stdc++.h>

using namespace std;

int power(int n) {
    if (n == 0)
        return 1;

    switch ((n - 1) % 4) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 8;
        case 3:
            return 6;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n;
    if (s.length() > 2)
        n = s[s.length() - 2] * 10 + s[s.length() - 1];
    else
        n = atoi(s.c_str());

    cout << power(n) << endl;
}
