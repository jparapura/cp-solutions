#include <bits/stdc++.h>

#define br "\n"
#define int int64_t

using namespace std;

const int MAXN = 1e5 + 3;
vector<vector<int>> edges;

int dp[MAXN];
bool visited[MAXN];
int ans;

void dfs(int v) {
    if (visited[v])
        return;
    visited[v] = true;

    int depth = -1;
    for (int w : edges[v]) {
        dfs(w);
        depth = max(depth, dp[w]);
    }
    depth++;
    dp[v] = depth;
    ans = max(ans, depth);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    edges.resize(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
    }

    for (int v = 0; v < N; v++) {
        if (visited[v] == false) {
            dfs(v);
        }
    }

    cout << ans << br;
}
