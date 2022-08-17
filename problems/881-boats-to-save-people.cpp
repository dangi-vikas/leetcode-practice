class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = people.size()-1;
        int boats = 0;
        vector<int> counts(limit+1, 0);
        
        for(int p : people) counts[p]++;
        
        int index = 0;
        for(int val=0; val<=limit; val++) 
            while(counts[val]-- > 0) people[index++] = val;
        
        while(left <= right) {
            if(people[left] + people[right] <= limit) {
                left++; 
                right--;
            }
            
            else right--;
            
            boats++;
        }
        
        return boats;
    }
};