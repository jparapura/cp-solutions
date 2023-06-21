#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;
int nums[MAXN];

int n;

void testCase();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        nums[i] = x > nums[i - 1] ? x : nums[i - 1];
    }

    nums[n + 1] = nums[n] + 1;

    while (m-- > 0) {
        testCase();
    }
    cout << "\n";
}


void testCase() {
    int q;
    cin >> q;

    int l = 0;
    int r = n + 1;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (nums[mid] >= q) {
            r = mid;
        }
        else if (nums[mid] < q) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << l << " ";
}

