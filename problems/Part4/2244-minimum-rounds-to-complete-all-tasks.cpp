class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        int ans = 0;

        for(int task : tasks) freq[task]++;

        for(auto task : freq) {
            if(task.second == 1) return -1;
            
            ans += task.second / 3;
            task.second %= 3;

            if(task.second % 3) ans += 1;
        }

        return ans;
    }
};