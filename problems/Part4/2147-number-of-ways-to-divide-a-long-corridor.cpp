class Solution {
    int mod = 1e9 + 7;

public:
    int numberOfWays(string corridor) {
        vector<int> seatNumber;
        long long int ans = 1;

        for(int i=0; i<corridor.size(); i++) 
            if(corridor[i] == 'S')
                seatNumber.push_back(i);
      
        if(seatNumber.size() % 2 != 0 || seatNumber.size() == 0)
            return 0;
            

        for(int i=2; i<seatNumber.size(); i+=2) 
            ans = ans * (seatNumber[i] - seatNumber[i-1]) % mod;

        return ans;
    }
};