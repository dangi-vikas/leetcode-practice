class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<long> ans;
        
        for(string &op : ops){
            if(op == "C") ans.pop_back();
            
            else if(op == "+"){
                int score = ans[ans.size() - 1] + ans[ans.size() - 2];
                ans.push_back(score);
            }
            
            else if(op == "D"){
                int score = ans[ans.size() -1];
                ans.push_back(score * 2);
            }
            
            else{
                ans.push_back(stoi(op));
            }
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
    }
};