class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> freq;
       
      string res = "";
           for(auto &i: licensePlate) 
			if(isalpha(i)) freq[tolower(i)]++; 
        
        for(auto &word : words)
        {
            bool valid = true;
            
            for(auto &ch: freq)
                if(ch.second > count(word.begin(), word.end(), ch.first)) {
                    valid = false;
                    break;
                }
            
            if(valid) if(!res.size() || res.size() > word.size()) res = word;
        }

        return res;
    }
};