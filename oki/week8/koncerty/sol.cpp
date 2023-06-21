#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 7;
int nums[MAXN];
int prefix[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int D;
    cin >> D;

    for (int i = 1; i <= D; i++) {
        cin >> nums[i];
        prefix[i] = prefix[i - 1] + nums[i];
    }

    int P;
    cin >> P;

    for (int i = 1; i <= P; i++) {
        int ds, dk;
        cin >> ds >> dk;
        cout << prefix[dk] - prefix[ds - 1] << endl;
    }
}
