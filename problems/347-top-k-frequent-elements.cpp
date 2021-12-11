class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int> count;
        
        for(int i=0; i<nums.size();i++)
            count[nums[i]]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>mi;
        
        for(auto &i : count){
            mi.push({i.second,i.first});
            if(mi.size() > k)
                mi.pop();
        }
        
         
        while(mi.size() > 0){
            ans.emplace_back(mi.top().second);
            mi.pop();
        }
        
        return ans;
    }
};