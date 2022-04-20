class comparator {
public:
    bool operator() (pair<char, int> p1, pair<char, int> p2){
        return p1.second < p2.second;
    } 
};
        

class Solution {    
public:
    string reorganizeString(string s) {
        unordered_map<char, int> count;
        priority_queue<pair<char, int>, vector<pair<char, int>>, comparator> freq; 
        string ans = "";
        pair<char, int> max, nextMax;
        
        for(char ch : s)  count[ch]++;
        for(auto c : count) freq.push({c.first, c.second});
        
        max = freq.top(); 
        freq.pop();
        
        while(true) {
            ans += max.first;
            max.second--;
            
            if(freq.size() == 0) {
                if(max.second == 0) return ans;
                else return "";
            }
            
            nextMax = freq.top();
            freq.pop();
            
            if(max.second != 0) freq.push(max);
            max = nextMax;
        }
        
        return ans;
    }
};