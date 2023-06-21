#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    map<char, char> m = {
        { '{', '}' },
        { '[', ']' },
        { '(', ')' },
    };

    for (char c : s) {
        if (m.count(c) > 0) {
            st.push(c);
        }
        else {
            if (st.empty())
                return false;

            char b = st.top();
            st.pop();

            if (m[b] != c)
                return false;
        }
    }
    return st.size() == 0;
}

int main() {
    cout << boolalpha;
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("{{({})}}") << endl;
    cout << isValid("{{([})}}") << endl;
    cout << isValid(")") << endl;
    cout << isValid(")))") << endl;
}
