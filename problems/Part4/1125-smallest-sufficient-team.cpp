class Solution {
public:
    int r, n; 
    vector<int> peoMask; 
    vector<long long> dp; 

    long long team(int skillsHad) {
        if (skillsHad == 0) return 0; 
        if (dp[skillsHad] != INT_MAX) return dp[skillsHad]; 
        
        long long ans = n;

        for(int i=0; i<n; i++) {
            int skills = skillsHad & ~peoMask[i];

            if(skills != skillsHad) {
                long long chosen = team(skills) | 1LL << i; 
                bitset<60> bChosen(chosen);

                if (bChosen.count() < bitset<60>(dp[skillsHad]).count())
                    dp[skillsHad] = chosen;
            }
        }

        return dp[skillsHad];
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        r = req_skills.size();
        n = people.size();
        unordered_map<string, int> skillNr;

        for(int i=0; i<r; i++)
            skillNr[req_skills[i]] = i;

        peoMask.assign(n, 0);

        for(int i=0; i<n; i++) 
            for(string& skill : people[i]) 
                peoMask[i] |= (1 << skillNr[skill]); 
            
        dp.assign(1<<r, INT_MAX);

        long long peoChosen = team((1<<r) - 1);  
        bitset<60> X(peoChosen);
        vector<int> ans;
        
        for (int i=0; i<n; i++)
            if (X[i]) ans.push_back(i); 
            
        return ans;
    }
};