#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int bigint;

const int SIEVE_LIMIT = 1e5 + 7;
bool sieve[SIEVE_LIMIT];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (bigint i = 2; i < SIEVE_LIMIT; i++) {
        if (sieve[i] == false) {
            for (bigint j = i + i; j < SIEVE_LIMIT; j += i) {
                sieve[j] = true;
            }
        }
    }

    int n;
    cin >> n;

    if (n <= 2) 
        cout << 1 << "\n";
    else
        cout << 2 << "\n";

    for (int i = 2; i <= n + 1; i++) {
        if (sieve[i] == false)
            cout << 1;
        else
            cout << 2;
        if (i != n + 1)
            cout << " ";
    }
    cout << "\n";
}
