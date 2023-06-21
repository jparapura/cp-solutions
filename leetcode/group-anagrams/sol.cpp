#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (string& s : strs) {
        array<int, 26> letters{ 0 };
        for (char c : s) {
            letters[c - 'a']++;
        }
        string hashValue;
        for (int x : letters) {
            hashValue += to_string(x) + ",";
        }
        m[hashValue].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& it : m) {
        result.push_back(it.second);
    }
    return result;
}

int main()
{
    vector<string> s1 = {"eat","tea","tan","ate","nat","bat"};
    auto r1 = groupAnagrams(s1);
    vector<string> s2 = {""};
    auto r2 = groupAnagrams(s2);
    vector<string> s3 = {"a"};
    auto r3 = groupAnagrams(s3);
    cout << " aaa";
}
