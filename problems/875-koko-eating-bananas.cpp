class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = piles[0];

        for(int pile : piles) 
            high = max(high, pile);

        while(low < high) {
            long mid = low + ((high - low) >> 1);

            if(!canEatAllBananas(piles, h, mid)) low = mid + 1;
            else high = mid;
        }

        return (int) low;
    }

    bool canEatAllBananas(vector<int>& piles, int hours, int currK) {
        long count = 0;

        for(long pile : piles) {
            count += pile / currK;
            if(pile % currK) count++;
        }

        return count <= hours;
    }
};