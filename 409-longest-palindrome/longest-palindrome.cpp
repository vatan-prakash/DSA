class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
         bool isoddfound=false;
        int count =0;
        if(s.size()==1) return 1;
        for(auto&freq:s){
            mp[freq]++;
           
        }

        for(auto&freq:mp){
            if(freq.second % 2==0){
            count+=freq.second;
            }
            else{
                count+=freq.second-1;
                isoddfound = true;
            }

            
        }

        if(isoddfound)count+=1;
        return count;
        

    }
};