class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size(), m=strs[0].size();
        
        if (strs.empty()) return "";
        if (n==1) return strs[0];
        
        for (int i=0; i<m; ++i) {
            for (const auto& j : strs) {
                if (i >= j.length() || j[i]!=strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};