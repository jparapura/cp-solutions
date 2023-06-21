#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int bigint;

bigint a, b;

string steps(bigint n) {
    if (n > b) {
        return "";
    }
    if (n == b)
        return to_string(n) + " ";
    string try1 = steps(2 * n);
    if (try1 != "")
        return to_string(n) + " " + try1;
    string try2 = steps(10 * n + 1);
    if (try2 != "")
        return to_string(n) + " " + try2;

    return "";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    string result = steps(a);
    if (result != "") {
        size_t count = std::count_if(result.begin(), result.end(), [](char c){ return c ==' '; });
        cout << "YES\n" << count << "\n" << result << "\n";
    }
    else {
        cout << "NO\n";
    }
}
