class Solution {
    typedef long long ll;

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll ans = getCost(nums, cost, nums[0]);

        ll low = *min_element(nums.begin(), nums.end());
        ll high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            ll mid = low + ((high - low) >> 1);

            ll preCost = getCost(nums, cost, mid);
            ll postCost = getCost(nums, cost, mid+1);

            ans = min(preCost, postCost);

            if(preCost > postCost) low = mid + 1;
            else high = mid - 1;
        }

        return ans;
    }

    ll getCost(vector<int>& nums, vector<int>& cost, int base) {
        ll currCost = 0;

        for(int i=0; i<nums.size(); i++) 
            currCost += 1L * abs(base - nums[i]) * cost[i];

        return currCost;
    }
};