class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      long long  int i=0;
      long long  int j=0;
      long long  int n=nums.size();
       long long int cursum=0;
       long long int maxsum=0;
        unordered_set<int> st;
        for(int j=0;j<n;j++){
            while(st.count(nums[j])){
                st.erase(nums[i]);
                cursum-=nums[i];
                i++;
            }
            cursum+=nums[j];
            st.insert(nums[j]);

            if(j-i+1==k){
                maxsum=max(maxsum,cursum);
                st.erase(nums[i]);
                cursum-=nums[i];
                i++;
            }
           

        }

        return maxsum;
    }
};