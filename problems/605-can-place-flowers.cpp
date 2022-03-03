class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        
        if(n == 0) return true;

        for(int i=0; i<len && n>0; ++i) {
            if(flowerbed[i] == 1) {
                ++i; continue;
            }
            
            int next = (i == len-1) ? 0 : flowerbed[i+1];
            if(next == 0) {
                --n; ++i; 
            }
        }

        return n == 0;
    }
};