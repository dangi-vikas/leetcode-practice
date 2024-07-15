class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        string ans, part;
        vector<string> temp;
        
        //splitting the path string by '/' character
        while(getline(ss, part, '/')){
            
            //the the variable in path is '.' or ''
            if(part=="" || part==".") continue;

            //if it is a valid directory
            if(part != "..") temp.emplace_back(part);

            //if it is ".." then moving one directory up
            else if(!temp.empty()) temp.pop_back();
        }
        
        //emptying the vector in a string separated by '/'
        for(string& part: temp) ans += "/" + part;
        
        return temp.empty() ? "/" : ans;
    }
};