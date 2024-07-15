class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        vector<pair<long, long>> v;
        
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){

                //check for absolute difference of values
                if((v[j].first-v[i].first)>t) break;

                //check for absolute difference of index
                if(abs(v[j].second-v[i].second)<=k) return true;
            }
        
        return false;
    }
};