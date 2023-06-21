#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int bigint;

const int SIEVE_LIMIT = 1e6 + 7;
int spf[SIEVE_LIMIT]; // smallest prime factor

inline void testCase() {
    int n;
    cin >> n;

    int c = 2;
    map<int, int> freq;

    while (n > 1) {
        freq[spf[n]]++;
        n /= spf[n];
    }

    bigint result = 1;

    for (auto entry : freq) {
        if (entry.second % 2 == 1) {
            result *= entry.first;
        }
    }

    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < SIEVE_LIMIT; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (int j = i + i; j < SIEVE_LIMIT; j += i) {
                spf[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        testCase();
    }
}
