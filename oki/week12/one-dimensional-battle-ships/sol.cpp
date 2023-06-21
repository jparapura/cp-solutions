#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
bool board[MAXN];
int moves[MAXN];
int n, k, a, m;

inline bool isPossible(int x) {
    for (int i = 1; i <= x; i++) {
        board[moves[i]] = true;
    }
    for (int i = x + 1; i <= m; i++) {
        board[moves[i]] = false;
    }

    int currShipSize = 0;
    int shipCount = 0;

    for (int i = 1; i <= n; i++) {
        // szukamy k przestrzeni wielkości a

        if (board[i] == true) {
            currShipSize = 0;
        }
        else {
            currShipSize++;
            if (currShipSize == a) {
                shipCount++;
                currShipSize = 0;
                i++; // statki nie mogą się dotykać
                if (shipCount == k) {
                    break;
                }
            }
        }
    }

    return shipCount >= k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> a >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> moves[i];
    }

    if (isPossible(m) == true) {
        cout << "-1\n";
        return 0;
    }

    int l = 1;
    int r = m;

    while (r - l >= 1) {
        int mid = (l + r) / 2;

        if (isPossible(mid)) {
            // da się rozmieścić statki
            l = mid + 1;
        }
        else {
            // nie da się rozmieścić statków
            r = mid;
        }
    }

    cout << l << "\n";
}
