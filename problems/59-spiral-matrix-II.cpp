class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        //if n=0 no matrix will be formed
        if(n==0) return {};
        
        //initialised matrix of nxn with zero
        vector<vector<int>> ans(n, vector<int> (n, 0));
        
        int num = 1;

         //initialising the boundary pointers and iterating
        for(int left=0, right=n-1,
                top=0, bottom=n-1;
            left<=right && top<=bottom;
            ++left, ++top, --right, --bottom){
            
            //Traversing and inserting in the ans vector
            
            //left to right
            for(int j=left; j<=right; ++j){
                ans[top][j] = num;
                num++;
            }
            
            //top to bottom
            for(int i=top+1; i<bottom; ++i){
                ans[i][right] = num;
                num++;
            }
            
            //right to left
            for(int j=right; top<bottom && j>=left; --j){
                ans[bottom][j] = num;
                num++;
            }
            
            //bottom to top
            for(int i=bottom-1; i>top && left<right; --i){
                ans[i][left] = num;
                num++;
            }
        }
        
        return ans;  
    }
};