class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), i;
        
        for(i=1; i<=n; i++)
            if(citations[n-i] < i) break;
        
        return i-1;
    }
};