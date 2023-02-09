class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> ideaSet;
        vector<vector<int>> ideaPairCount(26, vector<int>(26, 0));
        long ans = 0;

        for(string idea : ideas) ideaSet.insert(idea);

        for(string idea : ideas) {
            int firstCh = idea[0];

            for(char ch='a'; ch<='z'; ch++) {
                idea[0] = ch;

                if(ideaSet.find(idea) == ideaSet.end()) 
                    ideaPairCount[firstCh - 'a'][ch - 'a']++;
                
                idea[0] = firstCh;
            }
        }

        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                ans += ideaPairCount[i][j] * ideaPairCount[j][i];
            }
        }

        return ans;
    }
};