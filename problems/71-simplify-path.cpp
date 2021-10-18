class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        istringstream ss(path);
        string ans, i;
        
        //splitting the path string by '/' character
        while(getline(ss, i, '/')){
            
            //the the variable in path is '.' or ''
            if(i=="" || i==".") continue;

            //if it is a valid directory
            if(i != "..") v.emplace_back(i);

            //if it is ".." then moving one directory up
            else if(!v.empty()) v.pop_back();
        }
        
        //emptying the vector in a string separated by '/'
        for(auto& j: v) ans += "/" + j;
        
        return v.empty() ? "/" : ans;
    }
};