class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        
        //as index start from 0
        rowIndex++;
        
        //traversing the column and pushing the required value
        long long c = 1;
        for(int i=1; i<=rowIndex; i++){
            ans.push_back(c);
            c = c*(rowIndex-i)/i;
        }
        
        return ans;
    }
};