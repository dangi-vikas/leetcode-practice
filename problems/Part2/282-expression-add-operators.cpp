class Solution {
vector<string> ans;

public:
    vector<string> addOperators(string num, int target) {
        addOperatorsRec(0, "", 0, 0, num, target);
        
        return ans;
    }
    
    void addOperatorsRec(int ind, string path, long ansSoFar, long prevNum, string& num, int target) {
        if(ind == num.length()) {
            if(ansSoFar == target) ans.push_back(path);
            return;
        }
        
        string str = "";

        for(int i=ind; i<num.length(); i++) {
            str += num[i];
            long currNum = stol(str); 
            
            if(i>ind && num[ind] == '0') continue;
            
            if(ind == 0) 
                addOperatorsRec(i+1, path + str, currNum, currNum, num, target);
            
            else {
                addOperatorsRec(i+1, path + "+" + str, ansSoFar+currNum, currNum, num, target);
                addOperatorsRec(i+1, path + "-" + str, ansSoFar-currNum, -currNum, num, target);
                addOperatorsRec(i+1, path + "*" + str, ansSoFar-prevNum+prevNum*currNum, currNum*prevNum, num, target);
            }
        }
    }
};