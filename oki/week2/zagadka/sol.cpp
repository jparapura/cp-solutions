#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double A, B;
    cin >> A >> B;

    double x = A * B / (B - 1);

    // check if integer
    if (ceil(x) == floor(x)) 
        cout << x << endl;
    else
        cout << "NIE" << endl;
}
