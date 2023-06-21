#include <bits/stdc++.h>

using namespace std;

bool dfs(int v, vector<vector<int>>& edges, unordered_set<int>& visited, vector<bool>& canComplete) {
    if (canComplete[v])
        return true;

    if (visited.count(v))
        return false;

    visited.insert(v);
    for (int w : edges[v]) {
        if (dfs(w, edges, visited, canComplete) == false)
            return false;
    }

    canComplete[v] = true;
    return true;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses);
    for (vector<int>& p : prerequisites) {
        int before = p[1];
        int after = p[0];
        edges[after].push_back(before);
    }

    vector<bool> canComplete;
    canComplete.assign(numCourses, false);
    for (int start = 0; start < numCourses; start++) {
        unordered_set<int> visited;
        if (dfs(start, edges, visited, canComplete) == false)
            return false;
    }
    return true;
}


void printVector(vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> d = {{1,0}, {2,0}, {3, 1}, {3, 2}};
    cout << canFinish(4, d) << endl;

    vector<vector<int>> a = {{1, 0}};
    cout << canFinish(2, a) << endl;

    vector<vector<int>> b = {{0, 1}};
    cout << canFinish(2, b) << endl;

    vector<vector<int>> c = {{0, 1}, {1, 0}};
    cout << canFinish(2, c) << endl;


}


