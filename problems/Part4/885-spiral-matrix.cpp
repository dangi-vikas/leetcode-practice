class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans ;
        ans.push_back({rStart, cStart}); 
        int len = 1;
         
        while(ans.size() < (rows * cols)) {            
            for(int j=1; j<=len; j++)       
                if(isValid(rStart, cStart+j, rows, cols)) 
                    ans.push_back({rStart, cStart+j});
               
            cStart+=len;
                
            for(int i=1; i<=len; i++)
                if(isValid(rStart+i, cStart, rows, cols)) 
                    ans.push_back({rStart+i, cStart});      
            
            rStart += len;                        
            len++;
                
            for(int j=1; j<=len; j++)
                if(isValid(rStart, cStart-j, rows, cols)) 
                    ans.push_back({rStart, cStart-j});
           
            cStart -= len;
                
            for(int i=1; i<=len; i++)
                if(isValid(rStart-i, cStart, rows, cols)) 
                    ans.push_back({rStart-i, cStart});
            
            rStart -= len;
            len++;
        }
            
        return ans;
    }
    
    bool isValid(int i, int j, int n, int m) {
        if(i<0 || j<0 || j>=m || i>=n) return false;
        return true;
    }
};  