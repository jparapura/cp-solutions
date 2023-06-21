#include <bits/stdc++.h>

using namespace std;

stack<int> steps;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    while (b > a) {
        if (b % 2 == 0) {
            steps.push(b);
            b /= 2;
        }
        else if ((b - 1) % 10 == 0) {
            steps.push(b);
            b /= 10;
        }
        else break;
        
    }

    if (a != b) {
        cout << "NO\n";
        return 0;
    }

    steps.push(a);

    cout << "YES\n" << steps.size() << "\n";

    while (steps.empty() == false) {
        cout << steps.top() << " ";
        steps.pop();
    }
    
}
