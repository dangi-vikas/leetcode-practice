class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int max = 0, n = piles.size(), coins = 0;
        int chance = n / 3, turn = 1;

        for(int i : piles) 
            if(max < i) max = i;
        
        vector<int> freq(max+1, 0);

        for(int i : piles) freq[i]++;
       
        int i = max;

        while(chance != 0) {
            if(freq[i] > 0) {
                if(turn == 1) turn = 0;

                else {
                    chance--;
                    turn = 1;
                    coins += i;
                }

                freq[i]--;
            } 
            
            else i--;   
        }

        return coins;
    }
};