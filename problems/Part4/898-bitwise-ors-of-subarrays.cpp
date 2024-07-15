class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> a;
        unordered_set<int> s;
        
        for(int i=0; i<arr.size(); i++) {
            a.push_back(arr[i]);
            
            for(int j=0; j<a.size(); j++) {
                a[j] = a[j] | arr[i];
                
                if(j > 0 && a[j] == a[j-1]) {
                    a.erase(a.begin() + j - 1);
                    j--;
                    continue;
                }
                
                s.insert(a[j]);
            }
        }
        
        return s.size();
    }
};