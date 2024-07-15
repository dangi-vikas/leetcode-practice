class Solution {
    static bool compare(string& s1, string& s2) {
        string substr1 = string(s1.begin() + s1.find(' '), s1.end());
        string substr2 = string(s2.begin() + s2.find(' '), s2.end());
        
        return (substr1 == substr2) ? s1 < s2 : substr1 < substr2;
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int count = 0, index = logs.size()-1;
        
        for(int i=logs.size()-1; i>=0; i--) {
            int pos = logs[i].find(' ');
            
            if(isdigit(logs[i][pos+1]))
                swap(logs[index--], logs[i]);
            else count++;
        }
        
        sort(logs.begin(), logs.begin()+count, compare);
        
        return logs;
    }
};