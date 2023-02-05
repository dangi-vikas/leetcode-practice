class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int k = p.size(), n = s.size();
        vector<int> pCount(26, 0), sCount(26, 0);
        int i = 0, j = 0;

        if(n < k) return ans;

        while(j < k) {
            pCount[p[j] - 'a']++;
            sCount[s[j++] - 'a']++;
        }

        j--;
        
        while(j < n) {
            if(sCount ==  pCount) ans.push_back(i);        

            j++;

            if(j != n) sCount[s[j] - 'a']++;
            sCount[s[i] - 'a']--;

            i++;
        }

        return ans;
    }
};