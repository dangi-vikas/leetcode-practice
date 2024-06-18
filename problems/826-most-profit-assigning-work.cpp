class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> maxes;
        
        for(int i=0; i<difficulty.size(); i++) {
            if(maxes.find(difficulty[i]) == maxes.end()) 
                maxes[difficulty[i]] = profit[i];
    
            else maxes[difficulty[i]] = max(maxes[difficulty[i]], profit[i]);
        }
        
        vector<int> uniqueDifficulties;
        
        for(auto& i : maxes)
            uniqueDifficulties.push_back(i.first);
        
        vector<int> ordering(uniqueDifficulties.size() + 1, INT_MIN); 
        
        for(int i=1; i<uniqueDifficulties.size()+1; i++)
            ordering[i] = max(ordering[i-1], maxes[uniqueDifficulties[i-1]]);
        
        int total = 0;
        
        for(int i=0; i<worker.size(); i++) {    
            int index = upper_bound(uniqueDifficulties.begin(), uniqueDifficulties.end(), worker[i]) - uniqueDifficulties.begin() - 1;
            if(index == -1) continue; 
            total += ordering[index+1];
        }
        
        return total;
    } 
};
