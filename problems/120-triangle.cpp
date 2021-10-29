class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //starting from the bottom 
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<=i; j++){

                //adding the minimum of number at ith or (i+1)th position
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]); 
            }
        }
        
        //first element will come out to be the minimum sum
        return triangle[0][0];
    }
};