#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<string> s;
    for (int i = 0; i < tokens.size(); i++) {
        int x, y;
        if (tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "*" ||
            tokens[i] == "/") {
            y = atoi(s.top().c_str());
            s.pop();
            x = atoi(s.top().c_str());
            s.pop();
        }
        if (tokens[i] == "+")
            s.push(to_string(x + y));
        else if (tokens[i] == "-")
            s.push(to_string(x - y));
        else if (tokens[i] == "*")
            s.push(to_string(x * y));
        else if (tokens[i] == "/")
            s.push(to_string(x / y));
        else
            s.push(tokens[i]);
    }
    return atoi(s.top().c_str());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v1 = {"4","13","5","/","+"};
    cout << evalRPN(v1) << endl;
}
