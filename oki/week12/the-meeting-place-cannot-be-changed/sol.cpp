#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6e4 + 7;
const double EPS = 1e-6;
int pos[MAXN];
int spd[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed;
    cout << setprecision(12);

    int n;
    cin >> n;

    int first = INT_MAX;
    int last = INT_MIN;

    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        first = min(first, pos[i]);
        last = max(last, pos[i]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> spd[i];
    }

    double result = INT_MAX;

    double l = first;
    double r = last;

    if (r == l) {
        double a = 0;
        cout << a << "\n";
        return 0;
    }

    while (r - l >= EPS) {
        double p1 = (2 * l + r) / 3;
        double p2 = (2 * r + l) / 3;

        double p1Max = INT_MIN;
        double p2Max = INT_MIN;

        for (int i = 1; i <= n; i++) {
            double p1Cand = abs(p1 - pos[i]) / spd[i];
            double p2Cand = abs(p2 - pos[i]) / spd[i];

            p1Max = max(p1Max, p1Cand);
            p2Max = max(p2Max, p2Cand);
        }

        if (p1Max > p2Max) {
            l = p1;
        }
        else {
            r = p2;
        }

        result = min(result, p1Max);
        result = min(result, p2Max);
    }

    cout << result << "\n";
}
