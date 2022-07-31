class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int LETTERS = 26;
        int n = s.length();
        int lastOccurance[LETTERS] = {};
        
        for (int i = 0; i < n; i++) {
            lastOccurance[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        
        int currCand = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int tmp = lastOccurance[s[i] - 'a'];
            if (currCand < tmp)
                currCand = tmp;
            if (currCand == i) {
                result.push_back(currCand - start + 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};
