class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts; 
        vector<string> ans;
        
        for(string cpdomain : cpdomains) {
            int index = cpdomain.find(" ");
            
            if(index != string::npos) {
                int count = stoi(cpdomain.substr(0, index));
                string domain = cpdomain.substr(index+1);
            
                for(int i=domain.length(); i>=0; i--) {
                    if(domain[i] == '.') 
                        counts[domain.substr(i+1)] += count;
                    
                    if(i == 0) counts[domain] += count;
                }
                
            }
        }
        
        for(auto it : counts) 
                ans.push_back(to_string(it.second) + " " + it.first);
            
        return ans;
    }
};