class Solution {
    typedef long long ll;
    int mod = 1e9 + 7;

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> pascalTriangle(n+1);
    
        for(int i=0; i<n+1; i++) {
            pascalTriangle[i] = vector<ll>(i+1, 1);

            for(int j=1; j<i; j++){
                pascalTriangle[i][j] = (pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j]) % mod; 
            }
        }

        return (numOfWays(nums, pascalTriangle)) % mod - 1 ;
    }

    int numOfWays(vector<int>& nums, vector<vector<ll>>& pascalTriangle) {
        int n = nums.size();

        if(n <= 2) return 1;

        vector<int> leftSubtree, rightSubtree;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < nums[0]) leftSubtree.push_back(nums[i]);
            else rightSubtree.push_back(nums[i]);
        }

        ll leftWays = numOfWays(leftSubtree, pascalTriangle);
        ll rightWays = numOfWays(rightSubtree, pascalTriangle);
        int leftSubtreeLen = leftSubtree.size();

        return (((pascalTriangle[n-1][leftSubtreeLen] * leftWays) % mod) * rightWays) % mod;
    }
};