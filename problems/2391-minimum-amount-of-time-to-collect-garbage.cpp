class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m=0, p=0, g=0;
        int ans = 0;

        travel.insert(travel.begin(), 0);

        for(int i=0; i<garbage.size(); i++) {
            if(garbage[i].find('G') != string::npos) g = i;
            if(garbage[i].find('P') != string::npos) p = i;
            if(garbage[i].find('M') != string::npos) m = i;
            
            ans += garbage[i].size();
        }

        ans += travelDuration(m, travel);
        ans += travelDuration(g, travel);
        ans += travelDuration(p, travel);

        return ans;
    } 

    int travelDuration(int& truck, vector<int>& travel) {
        int sum = 0;

        for(int i=0; i<=truck; i++) 
            sum += travel[i];
        
        return sum;
    }
};