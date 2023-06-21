#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int bigint;

int N;
const int MAXN = 2e5 + 7;
int nums[MAXN];
bigint prefix[MAXN];


void testCase();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    sort(nums + 1, nums + N + 1);

    for (int i = N; i >= 1; i--) {
        prefix[N - i + 1] = prefix[N - i] + nums[i];
    }

    int Q;
    cin >> Q;
    while (Q-- > 0) {
        testCase();
    }
}

void testCase() {
    bigint q;
    cin >> q;

    int l = 1;
    int r = N;

    while (r - l > 0) {
        int mid = (l + r) / 2;

        if (prefix[mid] >= q) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
}
