#define ll long long 
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        
        for(int i=1; i<n-1; i++){
            ll n1 = stol(num.substr(0, i));
            if(to_string(n1) != num.substr(0, i)) break;
            
            for(int j=i+1; j<n; j++){
                ll n2 = stol(num.substr(i, j-i));
                if(to_string(n2) != num.substr(i, j-i)) break;
                
                bool isAdditive = isAdditiveNumberRec(n1, n2, num.substr(j), false);
                if(isAdditive) return true;
            }
        }
        
        return false;
    }
    
    bool isAdditiveNumberRec(ll& n1, ll& n2, string nums, bool isAdditive){
        if(nums.length() == 0 && isAdditive) return true;
        
        string n = to_string(n1 + n2);
        int index = min(n.length(), nums.length());
        ll n3 = stol(n);
        
        if(nums.substr(0, index) == n)
            return(isAdditiveNumberRec(n2, n3, nums.substr(index), true));
        
        return false;
    }
}; 