class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int m=matrix.size(), n=matrix[0].size();
        
        //iterating through the matrix
        for(int i=0; i<m; i++){

            //if the last element of the first column is zero
            if(matrix[i][0]==0) col0=0;

            for(int j=1; j<n; j++){

                //marking dummy column and rows as zero if the current elemrnt is zero
                if(matrix[i][j]==0) 
                    matrix[0][j] = matrix[i][0] = 0;

            }
        }
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=1; j--){

                /*if the any one of the dummy row or column element is zero 
                  setting the current element as zero*/
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j]=0;
            }
            
            //setting the first element as zero if col0 is false
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};