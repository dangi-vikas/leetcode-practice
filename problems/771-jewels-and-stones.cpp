class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> jewelCount(123, 0);
        int count = 0;
        
        for(int i=0; i<jewels.length(); i++)
            jewelCount[jewels[i]]++ ;
        
        for(int i=0; i<stones.length(); i++) 
            if(jewelCount[stones[i]] == 1)
                count++ ;
        
        return count;
    }
};