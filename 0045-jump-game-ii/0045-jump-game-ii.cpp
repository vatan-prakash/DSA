
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, -1); // Use n instead of n+1, and initialize with -1

        dp[n - 1] = 0; // Set the last element to 0, as you're already at the end

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > 0) {
                int Min = INT_MAX;
                for (int j = 1; j <= nums[i] && (i + j) < n; j++) {
                    if (dp[i + j] != -1) {
                        Min = std::min(Min, dp[i + j]);
                    }
                }
                if (Min != INT_MAX) {
                    dp[i] = Min + 1;
                }
            }
        }
        return dp[0];
    }
};