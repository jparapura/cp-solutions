#include <bits/stdc++.h>

using namespace std;

vector<int> countBits(int n) {
    vector<int> result;
    int nextJump = 1;
    int offset = 0;
    result.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (i == nextJump) {
            nextJump <<= 1;
            offset = i;
        }
        result.push_back(1 + result[i - offset]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v = countBits(n);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
