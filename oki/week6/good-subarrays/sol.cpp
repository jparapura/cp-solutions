#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000+7;
int nums[MAXN];
int prefix[MAXN];

void testCase();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0)
        testCase();
}

void testCase() {
    int n;
    cin >> n;
    map<int, int> occurenceCtr;
    unsigned long long acc = 0;
    char c;
    occurenceCtr[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        nums[i] = c - '0';
        nums[i] -= 1;
        prefix[i] = prefix[i - 1] + nums[i];
        acc += occurenceCtr[prefix[i]];
        occurenceCtr[prefix[i]] = occurenceCtr[prefix[i]] + 1;
    }
    cout << acc << endl;
}
