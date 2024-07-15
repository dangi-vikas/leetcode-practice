class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int ans = INT_MAX;
        vector<int> child(n);

        distributeCookies(cookies, child, 0, k, ans);

        return ans;
    }

    void distributeCookies(vector<int>& cookies, vector<int>& child, int ind, int k, int& ans) {
        if(ind == cookies.size()) {
            int maxEl = *max_element(child.begin(), child.end());
            ans = min(ans, maxEl);
            return;
        }

        for(int i=0; i<k; i++) {
            child[i] += cookies[ind];
            distributeCookies(cookies, child, ind+1, k, ans);
            child[i] -= cookies[ind];
        }
    }
};