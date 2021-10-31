class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalSurplus = 0, currSurplus=0;
        int startIndex = 0;
        
        for(int i=0; i<n; i++){
            totalSurplus += gas[i] - cost[i];
            currSurplus += gas[i] - cost[i];
            
            //if the trip cannot be completed
            if(currSurplus < 0){
                currSurplus = 0;

                //incrementing the starting point
                startIndex = i+1;
            }
        }
        
        //returning startIndex only if trip is possible
        return (totalSurplus<0) ? -1 : startIndex;
    }
};