#include <bits/stdc++.h>

using namespace std;

// ewentualnie można użyć vectora par
// jak działa sortowanie vectora par?
struct Person {
    int money;
    int factor;
};

bool personOrder(Person& p1, Person& p2) {
    return p1.money < p2.money;
}

typedef unsigned long long int bigint;

const int MAXN = 1e5 + 7;
Person ppl[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        cin >> ppl[i].money;
        cin >> ppl[i].factor;
    }

    if (n == 1) {
        cout << ppl[1].factor << "\n";
        return 0;
    }

    sort(ppl + 1, ppl + n + 1, personOrder);

    int l = 1;
    int r = 2;
    bigint maxFactor = ppl[1].factor;
    bigint currFactor = ppl[1].factor;

    while (r <= n) {
        if (ppl[l].money + d > ppl[r].money) {
            currFactor += ppl[r].factor;
            maxFactor = max(currFactor, maxFactor);
            r++;
        }
        else {
            currFactor -= ppl[l].factor;
            l++;
            // nigdy do tego nie dojdzie
            /* if (l > r) */
            /*     r++; */
        }
    }

    cout << maxFactor << "\n";
}
