#include<bits/stdc++.h>

using namespace std;

// TODO sortowanie w odwrotnej kolejności, jak zrobić sensownie parę
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int result = 1;
    int n = position.size();
    vector<pair<int, double>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = make_pair(position[i], (double)(target - position[i]) / (double)speed[i]);
    }
    sort(a.begin(), a.end());
    double leader = a[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i].second > leader) {
            result++;
            leader = a[i].second;
        }
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
    vector<int> pos1 = {10,8,0,5,3};
    vector<int> spe1 = {2,4,1,1,3};
    auto out1 = carFleet(12, pos1, spe1);
    cout << out1 << endl;

    /* vector<int> pos2 = {6,8}; */
    /* vector<int> spe2 = {3,2}; */
    /* auto out2 = carFleet(10, pos2, spe2); */
    /* cout << out2 << endl; */

    vector<int> pos2 = {0,4,2};
    vector<int> spe2 = {2,1,3};
    auto out2 = carFleet(10, pos2, spe2);
    cout << out2 << endl;
}
