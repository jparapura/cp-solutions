#include <bits/stdc++.h>

using namespace std;

typedef long long int bigint;

const int MAXN = 1e5+7;
int nums[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    sort(nums + 1, nums + n + 1);

    int maxOcc = 1;
    int number = nums[1];
    bigint have = nums[1];

    bigint l = 1;
    bigint r = 2;
    while (r <= n) {
        bigint need = (bigint)nums[r] * (bigint)((r - 1) - l + 1) - have;
        if (need <= k) {
            int occ = r - l + 1;
            if (occ > maxOcc) {
                number = nums[r];
                maxOcc = occ;
            }
            have += nums[r];
            r++;
        }
        else {
            have -= nums[l];
            l++;
            if (l == r) {
                have += nums[r];
                r++;
            }
        }
    }

    cout << maxOcc << " " << number << "\n";
}
