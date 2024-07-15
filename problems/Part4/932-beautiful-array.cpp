class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);
        
        while(ans.size() < n) {
            vector<int> temp;
            
            for(int el : ans) 
                if(2*el - 1 <= n)
                    temp.push_back(2*el - 1);

            for(int el : ans)
                if(2*el <= n)
                    temp.push_back(2*el);
           
            ans = temp;
        }
        
        return ans;
    }
};