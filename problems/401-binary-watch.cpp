class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        for(int hrs = 0; hrs < 12; hrs++)
            for(int mins = 0; mins < 60; mins++ )
            {
                bitset<4> b_hrs = bitset<4>(hrs); 
                bitset<6> b_mins = bitset<6>(mins);
                
                if(b_hrs.count() + b_mins.count() == turnedOn){       
                    string temp = "";
                    temp += to_string(hrs) + ":";
                    
                    if(mins < 10) temp += "0";
                    
                    temp += to_string(mins);
                    result.push_back(temp);
                }
            }
        
        return result;
    }
};