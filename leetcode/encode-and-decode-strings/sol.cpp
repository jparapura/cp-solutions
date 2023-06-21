#include <bits/stdc++.h>

using namespace std;

// to jest źle

string SEP = "#$#";
string encode(vector<string> &strs) {
    string result = "";
    int n = strs.size();
    for (int i = 0; i < n - 1; i++) {
        result += strs[i] + SEP;
    }
    result += strs[n - 1];
    return result;
}

vector<string> decode(string &str) {
    string buffer = "";
    vector<string> result;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        if (str[i] == '#' && str[i + 1] == '$' && str[i + 2] == '#') {
            result.push_back(buffer);
            buffer = "";
            i += 2;
            continue;
        }
        buffer += str[i];
    }
    result.push_back(buffer);
    return result;
}

int main() {
    vector<string> a1 = {"lint","code","love","you"};
    cout << encode(a1) << endl;

    string a2 = "lint#$#code#$#love#$#you";
    auto a3 = decode(a2);
    for (int i = 0; i < a3.size(); i++) {
        cout << a3[i] << " ";
    }
    cout << endl;
}
