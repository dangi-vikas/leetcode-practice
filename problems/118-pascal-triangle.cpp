class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        //traversing the rows
        for(int row=1; row<=numRows; row++) {
            int c = 1;
            vector<int> temp;

            //traversing the columns
            for(int i=1; i<=row; i++) {
                //pushing the required value
                temp.push_back(c);

                //updating the value of c for next column to push in
                c = c * (row-i) / i;
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};
