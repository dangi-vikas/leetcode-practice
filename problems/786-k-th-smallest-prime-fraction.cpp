class Solution {
    class comparator {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.first * b.second < a.second * b.first;
        }
    };
    
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
         
        for(int i=0; i<arr.size(); i++) {
            for(int j=i+1; j<arr.size(); j++) {
                pq.push({arr[i], arr[j]});
                if(pq.size() > k) pq.pop();
            }
        }
        
        pair<int, int> ans = pq.top();
        
        return {ans.first, ans.second};
    }
};