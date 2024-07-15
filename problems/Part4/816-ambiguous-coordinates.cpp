class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.length();
        vector<string> ans;
        
        for(int i=1; i<n-2; i++) {
            vector<string> temp1 = ambiguousCoordinatesRec(s.substr(1, i));
            vector<string> temp2 = ambiguousCoordinatesRec(s.substr(i+1, n-2-i));
            
            for(string& ch1 : temp1)
                for(string& ch2 : temp2)
                    ans.push_back("(" + ch1 + ", " + ch2 + ")");
        }
             
        return ans;
    }
    
    vector<string> ambiguousCoordinatesRec(string part) {
        int n = part.length();
        
        if(n==0 || (n>1 && part[0]=='0' && part[n-1]=='0')) return {};
        if(n>1 && part[0]=='0') return {"0." + part.substr(1)};
        if(n==1 || part[n-1] == '0') return {part};
        
        vector<string> coordinates = {part};
        
        for(int i=1; i<n; i++)
         coordinates.push_back(part.substr(0, i) + "." + part.substr(i));
        
        return coordinates;
    }
};