#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}


void print2dVector(vector<vector<int>>& a) {
    for (vector<int>& x : a) {
        for (int y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
}

typedef pair<int, int> pii;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < points.size(); i++) {
        vector<int> p = points[i];
        pairs.push_back(make_pair(p[0] * p[0] + p[1] * p[1], i));
    }
    priority_queue<pii, vector<pii>, greater<pii>> q(pairs.begin(), pairs.end());
    vector<vector<int>> ans;
    for (int i = 1; i <= k; i++) {
        ans.push_back(points[q.top().second]);
        q.pop();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> a = {{1,3}, {-2,2}};
    auto b = kClosest(a, 1);
    print2dVector(b);


    // 18, 26, 20
    a = {{3,3}, {5,-1}, {-2,4}};
    b = kClosest(a, 2);
    print2dVector(b);
}


