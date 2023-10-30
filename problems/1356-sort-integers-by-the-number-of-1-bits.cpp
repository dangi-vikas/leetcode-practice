class Solution {
public:
    int countBits(int n) {
        int c = 0;

        while(n) {
            c += (n & 1);
            n >>= 1;
        }

        return c;
    }

    vector<int> sortByBits(vector<int>& a) {
        vector<pair<int, int>> x;

        for(int i : a)
            x.push_back({countBits(i), i});
       
        sort(x.begin(), x.end());

        for(int i=0; i<a.size(); i++) 
            a[i] = x[i].second;

        return a;
    }
};