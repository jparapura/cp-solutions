#include <bits/stdc++.h>

using namespace std;

inline int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void testCase();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;

    while (z-- > 0) {
        testCase();
    }
}

void testCase() {
    int n, d;
    cin >> n >> d;

    cout << n / gcd(n, d) << "\n";
}
