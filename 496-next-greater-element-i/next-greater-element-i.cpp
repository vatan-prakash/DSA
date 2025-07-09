class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            int nextGreater = -1;

            // Find the index of num in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == num) {
                    // Look for next greater element to the right
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > num) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    break; // break from first loop once we found the index
                }
            }

            result.push_back(nextGreater);
        }

        return result;
    }
};
