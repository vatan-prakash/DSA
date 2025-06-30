class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char, int> nums = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int sum=0;
        int i=0;

        while(i<s.size()-1){
            if(nums[s[i]]<nums[s[i+1]]){
                sum-=nums[s[i]];
            }
            else{
                sum+=nums[s[i]];
            }
            i++;
        }
        sum+=nums[s[s.size()-1]];
        return sum;
    }
};