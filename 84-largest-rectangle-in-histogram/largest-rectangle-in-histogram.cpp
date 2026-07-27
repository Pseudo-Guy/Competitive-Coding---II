#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> st;

        std::vector<int> left(n);
        std::vector<int> right(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }

            st.push(i);
        }

        st = std::stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }

            st.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = std::max(maxArea, area);
        }

        return maxArea;
    }
};