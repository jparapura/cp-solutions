#include <bits/stdc++.h>

using namespace std;

class Solution {
    inline bool alphaNum(char c) {
        return ('A' <= c && c <= 'Z') ||
               ('a' <= c && c <= 'z') ||
               ('0' <= c && c <= '9');
    }
    
    inline char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return c - ('Z' - 'z');
        return c;
    }

public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !alphaNum(s[left]))
                left++;
            while (left < right && !alphaNum(s[right]))
                right--;
            if (toLower(s[left]) != toLower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main() {
    cout << boolalpha;
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome(" ") << endl;
    cout << s.isPalindrome("amanaplanacanalpanama") << endl;
    cout << s.isPalindrome(".,") << endl;
    cout << s.isPalindrome("0P") << endl;
}
