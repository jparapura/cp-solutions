#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30000+7;
int nums[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    sort(nums + 1, nums + N + 1);

    int globalMax = 0;

    int l = 1;
    int r = 3;
    while (r <= N) {
        if (nums[l] + nums [l + 1] > nums[r]) {
            globalMax = max(globalMax, r - l + 1);
            r++;
        }
        else {
            l++;
            if (r - l == 1)
                r++;
        }
    }

    cout << globalMax << endl;
}
