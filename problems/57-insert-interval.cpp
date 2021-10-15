class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        //if intervals is empty
        if(intervals.size()==0){
            ans.push_back(newInterval);  
            return ans;
        } 
        
        bool isMerged = false;
        
        //traversing intervals
        for(int i=0; i<intervals.size(); i++){

            //if the newInterval is subset of one of the intervals of (intervals vector)
            if(intervals[i][1]>=newInterval[0]){
                int j=i;
                int minI=newInterval[0];
                int maxI=newInterval[1];
                
                while(j<intervals.size() && intervals[j][0]<=newInterval[1]){
                    minI=min(intervals[j][0],minI);
                    maxI=max(intervals[j][1],maxI);
                    j++;
                }
                
                //pushing the interval with accomodating extremes 
                ans.push_back({minI,maxI});
                isMerged = true;
                
                while(j<intervals.size()){
                    ans.push_back(intervals[j]);
                    j++;
                }
                break;

            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        //if newInterval is greater than every interval
        if(isMerged == false){
            ans.push_back(newInterval);
            return ans;
        }

        return ans;
    }
};