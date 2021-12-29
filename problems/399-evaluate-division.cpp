class Solution {    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> mult;
        vector<double> ans;
        
        for (int i = 0; i < n; ++i) {
            mult[equations[i][0]][equations[i][1]] = values[i];
            mult[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        
        for (auto &query : queries) {
            unordered_set<string> visited;
            auto temp = dfs(query[0], query[1], visited, mult);
            ans.push_back(temp > 0 ? temp : -1.0);
        }
        
        return ans; 
    }
    
    double dfs(const string &numer, const string &denom, unordered_set<string>& visited, unordered_map<string, unordered_map<string, double>>& mult){
        
        if (mult[numer].find(denom) != mult[numer].end()) 
            return mult[numer][denom];

        for (auto &[nextNumer, relationship] : mult[numer]) 
            if (visited.find(nextNumer) == visited.end()) {
                visited.insert(nextNumer);
              
                auto temp = dfs(nextNumer, denom, visited, mult);
            
                if (temp > 0)  return relationship * temp;
            }

        return 0.0;
  }
};