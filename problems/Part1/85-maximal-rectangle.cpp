class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxArea = 0;
        vector<int> histogram(m, 0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                histogram[j] = (matrix[i][j] == '1') ? histogram[j] + 1 : 0;
            }
            
            maxArea = max(maxArea, largestRectangleArea(histogram));
        }
        
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for(int i=0; i<=n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                
                int width;
                
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                
                maxArea = max(maxArea, width * height);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};
