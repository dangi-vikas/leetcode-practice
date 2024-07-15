class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        if(paths.size() < 1) return {};
        
        unordered_map<string, vector<string>>files;
        vector<vector<string>> ans;
        
        for(string path : paths) {
            stringstream stream(path);
            string root = "", rest = "", dir = "", content = "";
            stream >> root;
            
            while(stream >> rest) {
                int pos = rest.find('(');
                dir = rest.substr(0, pos);
                content = rest.substr(pos);
                files[content].push_back(root + '/' + dir);
            }
        }
        
        for(auto &file : files) 
            if(file.second.size() > 1)
                ans.push_back(file.second);
        
        return ans;
    }
};