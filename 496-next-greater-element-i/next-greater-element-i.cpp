class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nge;  // stores next greater element for each number in nums2

        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];

            // Maintain decreasing stack
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // If stack not empty, top is next greater
            if (!st.empty()) {
                nge[curr] = st.top();
            } else {
                nge[curr] = -1;
            }

            // Push current element to stack
            st.push(curr);
        }

        // Build result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nge[num]);
        }

        return result;
    }
};
