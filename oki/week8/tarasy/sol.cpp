#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 7;
int nums[MAXN];

typedef unsigned long long bigint;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    int result = 1;

    for (int t = 1; t <= 2; t++) {
        int l = 1;
        int r = 2;
        bigint money = k;

        while (r <= n) {
            if (nums[r - 1] >= nums[r]) {
                result = max(result, r - l + 1);
                r++;
            }
            else {
                bigint need = nums[r] - nums[r - 1];
                if (money >= need) {
                    result = max(result, r - l + 1);
                    money -= need;
                    r++;
                }
                else {
                    l++;
                    if (r - l == 0)
                        r++;
                    else {
                        if (nums[l] > nums[l - 1]) {
                            money += nums[l] - nums[l - 1];
                        }
                    }
                }
            }
        }

        if (t == 1) {
            for (int i = 1; i <= n / 2; i++) {
                int tmp = nums[i];
                nums[i] = nums[n - i + 1];
                nums[n - i + 1] = tmp;
            }
        }
    }

    cout << result << "\n";
}
