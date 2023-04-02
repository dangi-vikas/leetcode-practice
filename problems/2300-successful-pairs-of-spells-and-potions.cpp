class Solution {
    typedef long long ll;

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ll n = potions.size();
        vector<int> ans;
        
        sort(potions.begin(), potions.end());

        for(int spell : spells) {
            ll factor = ceil ((double) success /  spell);
            ll pos = lower_bound(potions.begin(), potions.end(), factor) - potions.begin();

            ans.push_back(n - pos);
        }

        return ans;
    }
};