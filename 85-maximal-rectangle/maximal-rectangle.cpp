class Solution {
public:

    vector<int> NSL(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left[i] = st.top();
            } else {
                left[i] = -1;
            }

            st.push(i);
        }
        return left;
    }

    vector<int> NSR(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                right[i] = st.top();
            } else {
                right[i] = n;
            }

            st.push(i);
        }
        return right;
    }

    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);

        // First row
        for (int j = 0; j < m; j++) {
            heights[j] = matrix[0][j] == '1' ? 1 : 0;
        }

        int maxArea = MAH(heights);

        // Remaining rows
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j] = heights[j] + 1;  // since matrix[i][j] is '1'
                }
            }

            maxArea = max(maxArea, MAH(heights));
        }

        return maxArea;
    }
};
