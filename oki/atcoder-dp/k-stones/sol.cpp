#include <bits/stdc++.h>

#define br "\n"
#define int int64_t

using namespace std;

const int LOSS = 0;
const int WIN = 1;
const int MAXK = 1e5 + 3;

int dp[MAXK];
vector<int> a;

// dp[i] - wynik gry dla gracza, który wykonuje ruch przy stosie
// zwierającym i kamieni

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        dp[i] = LOSS;
    }
    
    for (int i = 1; i <= K; i++) {
        for (int s : a) {
            if (i - s == 0) {
                dp[i] = WIN;
                continue;
            }
            if (i - s < 0)
                continue;
            if (dp[i - s] == LOSS) {
                dp[i] = WIN;
                continue;
            }
        }
    }
    
    cout << (dp[K] == WIN ? "First" : "Second") << br;
}
