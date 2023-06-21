#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    if (N == 1) {
        cin >> N;
        cout << 1 << endl;
        return 0;
    }
    bigint a, b;
    cin >> a >> b;
    bigint acc = 1;
    if (a > b) {
        // pierwsze dwie wartości maleją, czyli Bajtek wraca do punktu
        // startowego, czyli musiał już minimum jeden basen przepłynąć
        acc++;
    }
    bool nondecreasing = a <= b;
    bigint prev = b;
    bigint curr;
    for (int i = 2; i < N; i++) {
        cin >> curr;
        if (nondecreasing) {
            if (prev > curr) {
                nondecreasing = false;
                acc++;
            }
        }
        else {
            if (prev < curr) {
                nondecreasing = true;
                acc++;
            }
        }
        prev = curr;
    }
    cout << acc << endl;
}
