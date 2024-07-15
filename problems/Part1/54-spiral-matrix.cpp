class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        //if thr matrix is empty
        if(matrix.empty()) return ans;
        
        //initialising the boundary pointers and iterating 
        for(int left=0, right=matrix[0].size()-1,
                top=0, bottom=matrix.size()-1;
            left<=right && top<=bottom;
            left++, top++, right--, bottom--){
            
            //Traversing and inserting in the ans vector

            //left to right
            for(int j=left; j<=right; j++){
                ans.emplace_back(matrix[top][j]);
            }
            
            //top to bottom
            for(int i=top+1; i<bottom; i++){
                ans.emplace_back(matrix[i][right]);
            }
            
            //right to left
            for(int j=right; top<bottom && j>=left; j--){
                ans.emplace_back(matrix[bottom][j]);
            }
            
            //bottom to top
            for(int i=bottom-1; i>top && left<right; i--){
                ans.emplace_back(matrix[i][left]);
            }
        }
        
        return ans;
    }
};