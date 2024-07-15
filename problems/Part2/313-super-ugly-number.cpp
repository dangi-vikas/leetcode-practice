 class Solution {
    using P = pair<long long, int>;
    
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
       vector<int> index(primes.size(), 0);
            vector<long long> nums;
            nums.push_back(1);      
            
            priority_queue<P, vector<P>, greater<P>> pq;    
            for (int i = 0; i < primes.size(); i++)
                pq.emplace(primes[i], i);  
            
            while (nums.size() < n){
                auto [value, id] = pq.top();   
                pq.pop();
                
                if (value != nums.back())     
                    nums.push_back(value);
                
                index[id]++;                            
                pq.emplace(nums[index[id]] * primes[id], id);        
            }
            
            return nums.back();
    }
};