class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        
        splitIntoFibonacciRec(num, ans, 0);
        
        return ans;
    }
    
    bool splitIntoFibonacciRec(string& num, vector<int>& ans, int index) {
        if(index == num.size()) 
            return ans.size() > 2;
        
        long long int n = 0;
        
        for(int i=index; i<num.size(); i++) {
            n = (n * 10) + (num[i] - '0');
            int size = ans.size();
            
            if(n > INT_MAX) return false;
            
            if((size < 2) || (ans[size-1] * 1LL + ans[size-2] * 1LL == n)){
                ans.push_back(n);
                if(splitIntoFibonacciRec(num, ans, i+1)) return true;
                ans.pop_back();
            }
            
            if(i == index && num[i] == '0') return false;
        }
        
        return false;
    }
};