#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

const int N = 150001;
int heights[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    uint currSum = 0;
    uint minSum = 100 * N;
    int result;

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        if (i < k)
            currSum += heights[i];
    }

    if (minSum > currSum) {
        minSum = currSum;
        result = 0;
    }

    for (int i = k; i < n; i++) {
        currSum += heights[i];
        currSum -= heights[i - k];
        if (minSum > currSum) {
            minSum = currSum;
            result = i - k + 1;
        }
    }

    cout << result + 1 << endl;
}
