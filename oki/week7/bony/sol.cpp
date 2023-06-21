#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

const int MAXBI = 1e6+7;

bool vouchers[MAXBI];
int cache[MAXBI];
bool bought[MAXBI];
vector<bigint> result;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int voucher;
        cin >> voucher;
        vouchers[voucher] = true;
    }

    int n;
    cin >> n;
    bigint visitors = 0;
    // złożoność wychodzi O(nlogn) - dowód w pliku complexity-proof.jpg
    for (int i = 1; i <= n; i++) {
        int clients; // gdyby tu był bigint, to by jeden test sfailował przez czas
        cin >> clients;
        int soldTodayAmt = 0;
        
        for (int i = cache[clients] + clients; i <= 1e6; i+= clients) {
            if (soldTodayAmt == clients) break;
            if (bought[i]) continue;
            cache[clients] = i;
            bought[i] = true;
            soldTodayAmt++;
            visitors++;
            if (vouchers[i]) result.push_back(visitors);
        }
        visitors += clients - soldTodayAmt;
    }
    
    cout << result.size() << endl;
    for (bigint x : result) {
        cout << x << endl;
    }
}
