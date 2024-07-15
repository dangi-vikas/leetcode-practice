class Solution {
    #define mod 1000000007
    int dp[51][51][11];

public:

    bool isValid(vector<string>& nums, int i1, int j1, int i2, int j2){
        for(int i=i1; i<=j1; i++)
            for(int j=i2; j<=j2; j++)
                if(nums[i][j] == 'A') return true;
        
        return false;
    }

    
    int ways(vector<string>& nums, int k, int i1, int j1, int i2, int j2){
        if(k == 0) return (isValid(nums, i1, j1, i2, j2)) ? 1 : 0;
        if(dp[i1][i2][k] != -1) return dp[i1][i2][k];
    
        int vertical = 0, horizontal = 0;

        for(int i=i1; i<j1; i++) {
            if(isValid(nums, i1, i, i2, j2)) {
                horizontal += ways(nums, k-1, i+1, j1, i2, j2);
                horizontal = horizontal % (mod);
            }
        }

        for(int j=i2; j<j2; j++) {
            if(isValid(nums, i1, j1, i2, j)) {
                vertical += ways(nums, k-1, i1, j1, j+1, j2);
                vertical = vertical % (mod);
            }
        }

        return dp[i1][i2][k] = (vertical + horizontal) % mod;
    }

    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        return ways(pizza, k-1, 0, pizza.size() - 1, 0, pizza[0].size() - 1);
    }
};