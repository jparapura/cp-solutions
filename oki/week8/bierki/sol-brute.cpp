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
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                if (nums[i] >= nums[j] + nums[k] ||
                    nums[j] >= nums[i] + nums[k] ||
                    nums[k] >= nums[i] + nums[j]) {
                    cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                }

            }
        }
    }
}
