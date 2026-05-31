class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int i=0;
        int j=0;
        unordered_set<char> seen;

        while(j<s.size()){
            
            if(seen.count(s[j])){
              seen.erase(s[i]);
              i++;
            }
            else{
                seen.insert(s[j]);// i ko hatenge kyuki j loop me hai
                maxlen=max(maxlen,j-i+1);
                j++;
            }
           
        }
        return maxlen;
    }
};