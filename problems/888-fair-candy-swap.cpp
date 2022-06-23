class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0); 
        int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        
        sort(bobSizes.begin(),bobSizes.end());
                                  
        for(int i=0; i<aliceSizes.size(); i++) {
            int x  = aliceSizes[i];
            vector<int> ans;
            ans.push_back(x);
            
            int y = (bobSum - aliceSum) / 2 + x;
            
            if(y <= 0) continue;
            
            int low = 0, high = bobSizes.size()-1;
            
            while(low <= high) {
                int mid = low + ((high-low) >> 1);
                
                if(bobSizes[mid] == y) {
                    ans.push_back(y);
                    return ans;
                }
                
                if(bobSizes[mid] < y) low = mid + 1;
                
                else high = mid - 1;
            }
        }
                                  
        return {};
    }
};