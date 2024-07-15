class Solution {
public:
    int binaryGap(int n) {
        int i, prev, maxDiff, pos;
        prev = maxDiff = 0;
        i = pos = 1;
        
        while(i <= n) {
            if(i & n) {
                if(prev == 0) 
                    prev = pos;
                else {
                    maxDiff = max(pos-prev, maxDiff);
                    prev = pos;
                }
            }
            
            i = i << 1;
            pos++;
        }
        
        return maxDiff;
    }
};
