class Solution {
    int ans = 0;
    
public:
    int maxLength(vector<string>& arr) {
        maxLengthRec(arr, 0, "", arr.size());  
        return ans;
    }
    
    void maxLengthRec(vector<string>& arr, int index, string container, int n) {
        if(!isUnique(container)) return;
        
        if(index == n) {
            int size = container.size();
            ans = max(ans, size);
            return;
        }
        
        maxLengthRec(arr, index+1, container+arr[index], n);
        maxLengthRec(arr, index+1, container, n);
    }
    
    bool isUnique(string& s) {
        unordered_set<char> sSet;
        
        for(char ch : s) {
            if(sSet.find(ch) != sSet.end())
                return false;
            
            sSet.insert(ch);
        }
        
        return true;
    }
};
