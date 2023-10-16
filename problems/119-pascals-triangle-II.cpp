class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long c = 1;
        
        //as index start from 0
        rowIndex++;
        
        //traversing the column and pushing the required value
        for(int i=1; i<=rowIndex; i++) {
            ans.push_back(c);
            c = c * (rowIndex-i) / i;
        }
        
        return ans;
    }
};