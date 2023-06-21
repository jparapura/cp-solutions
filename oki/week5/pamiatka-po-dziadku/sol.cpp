#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

typedef long long int bigint;

const int MAXN = 1000000+7;
bigint nums[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // maksymalna podtablica nie korzysta z cykliczności
    bigint currSum = 0;
    bigint maxSum = LONG_MIN;
    for (int i = 0; i < n; i++) {
        currSum += nums[i];
        maxSum = max(currSum, maxSum);
        currSum = max((bigint)0, currSum);
    }

    bigint firstCaseMax = maxSum;

    // maksymalna tablica korzysta z cykliczności
    currSum = 0;
    bigint minSum = LONG_MAX;
    int startCandidate, startBest, endBest;
    for (int i = 0; i < n; i++) {
        currSum += nums[i];
        if (minSum > currSum) {
            minSum = currSum;
            startBest = startCandidate;
            endBest = i;
        }
        if (currSum > 0) {
            currSum = 0;
            startCandidate = i + 1;
        }
    }

    // liczymy sumę elementów innych niż te należące do minimalnej podtablicy

    // corner case - wszystkie liczby ujemne
    if (startBest == 0 && endBest == n - 1) {
        cout << firstCaseMax << endl;
        return 0;
    }

    bigint secondCaseMax = 0;
    for (int i = 0; i < n; i++) {
        if (i >= startBest && i <= endBest) {
            continue;
        }
        secondCaseMax += nums[i];
    }

    bigint result = max(secondCaseMax, firstCaseMax);
    cout << result << endl;
}
