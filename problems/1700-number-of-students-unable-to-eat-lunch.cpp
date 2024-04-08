class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2, 0);
        int remaining = sandwiches.size();
        
        for(int student : students)
            counts[student]++;

        for(int sandwich : sandwiches) {
            if(counts[sandwich] == 0)
                break;
            
            if(remaining == 0)
                break;
            
            counts[sandwich]--;
            remaining--;
        }

        return remaining;
    }
};
