class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        //if intervals is empty
        if(intervals.size() == 0) return ans;
        
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        
        for(auto i : intervals){

            //if the next interval is a subinterval 
            //taking the greater interval
            if(i[0] <= temp[1]){
                temp[1] = max(temp[1], i[1]);
            }
            
            //if both are mutually exclusive pushing in ans
            else{
                ans.push_back(temp);
                temp = i;
            }
        }
        ans.push_back(temp);
        
        return ans;
    }
};