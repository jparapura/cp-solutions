#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int bigint;

const int SIEVE_LIMIT = 1e6 + 7;
bool sieve[SIEVE_LIMIT];
vector<int> primes;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (bigint i = 2; i < SIEVE_LIMIT; i++) {
        if (sieve[i] == false) {
            primes.push_back(i);
            for (bigint j = i + i; j < SIEVE_LIMIT; j += i) {
                sieve[j] = true;
            }
        }
    }

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        bigint q;
        cin >> q;

        double root = sqrt(q);

        if (floor(root) != ceil(root)) {
            cout << "NO\n";
            continue;
        }
        
        if (binary_search(primes.begin(), primes.end(), root))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
