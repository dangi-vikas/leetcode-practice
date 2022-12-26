class Solution {
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& b) {
        vector<int>ans;

        sort(a.begin(), a.end());

        for(int i=1; i<a.size(); i++)
            a[i] = a[i] + a[i-1];

        for(int i=0; i<b.size(); i++) {
            int ind = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            ans.push_back(ind);
        }

        return ans;
    }
};
