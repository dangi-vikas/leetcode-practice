class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001);
        int n = target.size(), maxEl =- 1;
        
        for(int i=0; i<n; i++) {
            int x = target[i], a = arr[i];
            
            freq[x]++;
            freq[a]--;
            maxEl = max({maxEl, x, a});
        }
        
        for(int x=1; x<=maxEl; x++) {
            if(freq[x] != 0) {
                return 0;
            }
        }
        
        return 1;
    }
};