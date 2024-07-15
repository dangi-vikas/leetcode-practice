class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> choiceMap;
        int minimum= INT_MAX;
        
        for(int i=0; i<list1.size(); i++)
            choiceMap[list1[i]]= i;
        
        for(int i=0; i<list2.size(); i++)
            if(choiceMap.find(list2[i])!= choiceMap.end())
                minimum = min(minimum, i + choiceMap[list2[i]]);
            
        for(int i=0; i<list2.size(); i++)
            if(choiceMap.find(list2[i])!= choiceMap.end())
                if(minimum == i + choiceMap[list2[i]])
                     ans.push_back(list2[i]);                     
                
        return ans;
    }
};