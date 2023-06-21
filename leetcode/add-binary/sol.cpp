#include <bits/stdc++.h>

using namespace std;

string addBinary(string a, string b) {
    if (b.size() > a.size()) {
        string t = a;
        a = b;
        b = t;
    }
    int n = a.size();
    int m = b.size();
    string padding = "";
    for (int i = 0; i < n - m; i++) {
        padding += '0';
    }
    b = padding + b;
    int carry = 0;
    string result;
    result.assign(n + 1, '0');
    for (int i = n - 1; i >= 0; i--) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        result[i + 1] = ((x + y + carry) % 2) + '0';
        carry = (x + y + carry) / 2;
    }
    if (carry != 0)
        result[0] = '1';
    if (result[0] == '0')
        result = result.substr(1, n);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << addBinary("11", "1") << endl;
    cout << addBinary("1010", "1011") << endl;
    cout << addBinary("0", "0") << endl;
}
