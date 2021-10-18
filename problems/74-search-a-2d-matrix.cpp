class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //if the matrix is empty
        if(!matrix.size()) return false;
        
        int m=matrix.size(), n=matrix[0].size();
        int low=0, high=(m*n)-1;
        
        //binary searching treating matrix like a 1D array
        //only possible because of the properties of given matrix

        while(high>=low){
            int mid = low + ((high-low)>>1);

            /*finding the index of the element of the element as if  
              the matrix is a 1D array*/

            if(matrix[mid/n][mid%n] == target) return true;
            if(matrix[mid/n][mid%n] < target) low = mid+1;
            else high = mid-1;
        }

        //if the element is not found in the array 
        return false;
    }
};