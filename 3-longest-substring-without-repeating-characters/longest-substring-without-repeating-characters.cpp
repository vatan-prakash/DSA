class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        for(int i=0;i<s.size();i++) {
            unordered_set<char> seen;
            for(int j=i;j<s.size();j++) {
              if(seen.count(s[j])) break;
              seen.insert(s[j]);
              maxlen=max(maxlen,j-i+1);
             }
        }
        return maxlen;
    }
};