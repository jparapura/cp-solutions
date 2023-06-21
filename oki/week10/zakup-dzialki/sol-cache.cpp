#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;
int nums[MAXN];
int n, q;
map<int, int> cache;

void query(int where);

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        auto cached = cache.find(x);
        if (cached != cache.end()) {
            cout << (*cached).second << endl;
            continue;
        }
        query(x);
    }
}

void query(int where) {
    int l = 1;
    int r = n;
    while (r - l != 1) {
        int mid = (l + r) / 2;
        if (nums[mid] == where) {
            cout << 0 << endl;
            return;
        }
        else if (nums[mid] > where) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    int result = min(abs(nums[r] - where), abs(nums[l] - where));
    cout << result << endl;
    cache.insert({ where, result });
}
