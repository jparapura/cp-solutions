#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

const int MAXN = 1e5+7;
bigint nums[MAXN];

// gąsienica = two pointers
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0, right = -1;
    bigint acc = 0;
    int books = 0;
    int maxBooks = 0;
    while (true) {
        if (right + 1 >= n) break;
        if (nums[right + 1] > t) {
            // nie ma szans na uwzględnienie tej książki
            // przywracamy left, right, books i acc do
            // wartości początkowych z pewnym offsetem
            left = right + 2;
            right = right + 1;
            books = 0;
            acc = 0;
            continue;
        }
        if (acc + nums[right + 1] <= t) {
            acc += nums[++right];
            maxBooks = max(++books, maxBooks);
        }
        else {
            acc -= nums[left++];
            books--;
        }
    }
    cout << maxBooks << endl;
}
