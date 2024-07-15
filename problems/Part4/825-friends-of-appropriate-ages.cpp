class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        int n = ages.size(), ans = 0;;
        
        for(int i=0; i<n; i++) count[ages[i]]++;
                
        for(int i=15; i<=120; i++)  ans += count[i] * (count[i] - 1);
      
        for(int i=1; i<=120; i++) 
            for(int j=1; j<i; j++) 
                if(j > (i/2) + 7) ans += count[i] * count[j];
         
        return ans; 
    }
};