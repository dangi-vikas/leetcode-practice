class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string out = "";
        bool ignored =  false;
        
        for(string& line : source) {
            for (int i=0; i<line.size(); i++){
                if (ignored) {
                    if (line[i]=='*' && i+1<line.size() && line[i+1]=='/'){
                        ignored = false;
                        i++;
                    }
                }
                
                else {
                    if(line[i]=='/' && i+1<line.size()){
                        if (line[i+1]=='*') {
                            ignored = true;
                            i++;
                        }
                        else if(line[i+1] == '/') break;
                        else out.push_back(line[i]);    
                    }
                    
                    else out.push_back(line[i]);
                }
            }
            
            if(!out.empty() && !ignored) {
                ans.push_back(out);
                out = "";
            }
        }
        
        return ans;
    }
};