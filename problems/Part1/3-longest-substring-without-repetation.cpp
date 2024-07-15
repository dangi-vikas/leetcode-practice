class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> visited;
        int maxLength = 0;
        int currLength = 0;
        
        int l=0, r=0;
        
        for(r=0; r<s.length(); r++){
            if (visited.find(s[r]) != visited.end())
            {
                // If the number is repeated, move the left pointer to position after the last occurrence
                l = max(l, visited[s[r]] + 1);
            }

            // Updating the last seen value of the character
            visited[s[r]] = r;
            maxLength = max(maxLength,r - l + 1);
        }
        
        return maxLength;
    }
};