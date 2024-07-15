class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int ans = 0;
        
        for(int answer : answers)
            count[answer]++;
        
        for(auto it=count.begin(); it!=count.end(); it++) {
            int groupSize = it->first + 1;
            int reportees = it->second;
            int numGroups = (int) ceil(reportees * 1.0 / groupSize * 1.0);
            
            ans += groupSize * numGroups;
        }
        
        return ans;
    }
};