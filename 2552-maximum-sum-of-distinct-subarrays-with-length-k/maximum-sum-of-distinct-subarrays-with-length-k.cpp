class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      long long  int i=0;
      long long  int j=0;
      long long  int n=nums.size();
       long long int cursum=0;
       long long int maxsum=0;
        unordered_set<int> st;
        
          while(j<n){
        while(st.count(nums[j])){
                cursum-=nums[i];
                st.erase(nums[i]);
                i++;
            }

            st.insert(nums[j]);
            cursum+=nums[j];

            while(j-i+1==k){
                maxsum=max(cursum,maxsum);
                cursum-=nums[i];
                st.erase(nums[i]);
                i++;

            }
         j++;
           }

        return maxsum;
    }
};