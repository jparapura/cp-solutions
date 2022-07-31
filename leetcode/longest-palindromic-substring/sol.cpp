#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        if (n == 2) {
            if (s[0] == s[1]) return s;
            string r(1, s[0]);
            return r;
        }

        string result;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int left = i;
                int right = j == 1 ? i - 1 : i;
                int currLen = j == 1 ? 0 : 1;
                while (left >= 1 && right < n - 1) {
                    left--;
                    right++;
                    if (s[left] == s[right]) {
                        currLen += 2;
                        if (maxLen < currLen) {
                            maxLen = currLen;
                            result = s.substr(left, right - left + 1);
                        }
                    }
                    else break;
                }
                if (maxLen < currLen) {
                    maxLen = currLen;
                    result = s.substr(left, right - left + 1);
                }
            }
        }
        return result;
    }
};


int main() {
    Solution s;

    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
}
