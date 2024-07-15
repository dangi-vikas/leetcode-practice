class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWaitingTime = 0;
        int currentTime = 0;

        for (const auto& customer : customers) {
            int arrival = customer[0];
            int service = customer[1];
            
            if (currentTime < arrival) {
                currentTime = arrival;
            }
            
            int waitingTime = currentTime - arrival + service;
            totalWaitingTime += waitingTime;
            currentTime += service;
        }

        return totalWaitingTime / customers.size();
    }
};
