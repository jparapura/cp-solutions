#include <bits/stdc++.h>

using namespace std;

const int N = 30000;

int tab[N];
bool visited[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ctr = 0;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            int curr = i;
            while (visited[curr] == false) {
                visited[curr] = true;
                curr = tab[curr] - 1;
            }
            ctr++;
        }
    }

    cout << ctr << endl;
}
