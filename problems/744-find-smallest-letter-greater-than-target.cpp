class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int high = letters.size()-1, low = 0;
        char ans = letters[0];

        while(high >= low) {
            int mid = low + ((high - low) >> 1);

            if(letters[mid] > target) {
                high = mid - 1;
                ans = letters[mid];
            } 

            else if(letters[mid] <= target) low = mid + 1;
        }

        return ans;
    }
};