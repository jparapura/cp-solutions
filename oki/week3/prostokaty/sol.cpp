#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int result = 0;
    
    for (int blocksAmt = 1; blocksAmt <= n; blocksAmt++) {
        for (int i = 1; i <= sqrt(blocksAmt); i++) {
            if (blocksAmt % i == 0) 
                result++;
        }
    }

    cout << result << endl;
}
