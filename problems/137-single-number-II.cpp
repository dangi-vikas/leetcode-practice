class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int, int> count;
        
        //storing the count of every element in a map
        for(int num : nums) count[num]++;
        
        for(auto i=count.begin(); i!=count.end(); i++)
            
            //if the count of the an element is 1
            if(i->second == 1) return i->first;
        
        return 0;
    }
};