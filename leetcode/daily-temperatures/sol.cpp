#include<bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> s;
    int n = temperatures.size();
    vector<int> result(n);
    result.assign(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        while (s.empty() == false && temperatures[i] >= s.top().first) {
            s.pop();
        }
        if (s.empty() == false && temperatures[i] < s.top().first) {
            result[i] = s.top().second - i;
        }
        s.push(make_pair(temperatures[i], i));
    }
    return result;
}

void p(vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> in1 = {73,74,75,71,69,72,76,73};
    auto out1 = dailyTemperatures(in1);
    p(out1);
}
