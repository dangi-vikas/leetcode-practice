class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string t;
        int length = s.length();
        
        for(int i=0; i<indices.size(); ++i) 
            length += (targets[i].length()) - (sources[i].length());
        
        if (length > t.capacity()) t.reserve(length);
        
        vector<int> order(indices.size());
        
        for (int i = 0; i < order.size(); ++i) order[i] = i;
        
        sort(order.begin(), order.end(), [&] (auto a, auto b) {
            return indices[a] < indices[b];
        });
        
        int pos{0};
        
        for (auto idx : order) {
            t += s.substr(pos, indices[idx] - pos);
            
            if (s.substr(indices[idx], sources[idx].length()) == sources[idx]) {
                t += targets[idx];
                pos = indices[idx] + sources[idx].length();
            } 
            
            else pos = indices[idx];
        }
        
        if (pos < s.length()) t += s.substr(pos);
        
        return t;
    }
};