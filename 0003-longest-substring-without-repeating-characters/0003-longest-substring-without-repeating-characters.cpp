class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ml=0;
       int ans=0;
       for(int i=0;i<s.length();i++){
         unordered_set<char> st;
          for(int j=i;j<s.length();j++){
              if(st.count(s[j])) break;
              st.insert(s[j]);
              ans=max(ans,j-i+1);
        
        }
       }
       return ans;
    }
};